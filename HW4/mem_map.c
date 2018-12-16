#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;
void print_details(int, char);

void print_details(int argc, char **argv) {
   int i=0;
   printf("argc: addr=%x val=%x\n",&argc,argc);
   printf("argv: addr=%x val=%x\n\n",&argv,argv);
   while (*argv) {
         printf("arg%d: argv=%x [ *argv=%x == &(**argv)=%x ] **argv=%x **argv=%c *argv=%s\n",\ i++,argv,*argv,&(**argv),**argv,**argv,*argv);
         argv++;
}
   printf("arg%d: argv=%x [ *argv=%x == &(**argv)=%x ]\n", i++, argv, *argv, &(**argv))
}



int main(int argc, char *argv[]){
     argc: addr=7487ae6c val=5
     argv: addr=7478ae60 val=7487af88

     arg0: argv=7487af88 [ *argv=7487b49d == &(**argv)=7487b49d ] **argv=68 **argv=h *argv=hello
     arg1: argv=7487af90 [ *argv=7487b4a3 == &(**argv)=7487b4a3 ] **argv=74 **argv=t *argv=this
     arg2: argv=7487af98 [ *argv=7487b4a8 == &(**argv)=7487b4a8 ] **argv=69 **argv=i *argv=is
     arg3: argv=7487afa0 [ *argv=7487b4ab == &(**argv)=7487b4ab ] **argv=61 **argv=a *argv=a
     arg4: argv=7487afa8 [ *argv=7487b4ad == &(**argv)=7487b4ad ] **argv=74 **argv=t *argv=test
     arg5:argv=7487afb0 [ *argv=0 == &(**argv)=0]
     print_details();
}

