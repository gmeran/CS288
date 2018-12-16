//CS288 HW10


#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define NELMS 10000000
#define MASTER 0
#define MAXPROCS 16

int dot_product();
void init_lst();
void print_lst();

int main(int argc, char **argv) {
  int i,n,vector_x[NELMS],vector_y[NELMS];
  int prod, sidx, eidx, size;
  int pid, nprocs, rank;
  double stime,etime;
  MPI_Status status;
  MPI_Comm world;

  n = atoi(argv[1]);
  if (n > NELMS) { 
      printf("n=%d > N=%d\n",n,NELMS); exit(1); 
  }

  MPI_Init(&argc, &argv);
  world = MPI_COMM_WORLD;
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  int portion = n/nprocs;
  sidx = pid*portion;
  eidx = sidx+portion;
  init_lst(vector_x,n);
  init_lst(vector_y,n);
  int tmp_prod[nprocs];
  for(i=0; i<nprocs; i++){
      tmp_prod[i] = 0;
  }

  stime = MPI_Wtime();
        if (pid == MASTER){
           prod = dot_product(sidx, eidx, vector_x, vector_y, n);
           for(i=1; i<nprocs; i++){
              MPI_Recv(&tmp_prod[i-1],1,MPI_INT,i,123,MPI_COMM_WORLD,&status);
           }
        }
        else {
             prod = dot_product(sidx, eidx, vector_x, vector_y, n);
             MPI_Send(&prod, 1, MPI_INT, MASTER, 123, MPI_COMM_WORLD);
        }
        if (pid == MASTER){
             for(i=0; i<nprocs; i++){
                  prod += tmp_prod[i];
             } 
        }
  etime = MPI_Wtime();

  if (pid == MASTER) {
    printf("pid=%d: final prod=%d\n",pid,prod);
    printf("pid=%d: elapsed=%f\n",pid,etime-stime);
  }
  MPI_Finalize();
}

int dot_product(int s,int e,int x[], int y[], int n){
  int i,prod=0;
  for(i=s; i<e; i++){
      prod = prod+x[i]*y[i];
  }
  
  return prod;
}

void init_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) { 
        *l++ = i;
  }
}
void print_lst(int s,int e, int *l){
  int i;
  for (i=s; i<e; i++) {
    printf("%x ",l[i]);
  }
  printf("\n");
}

// end of file
