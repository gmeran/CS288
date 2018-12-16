#!/bin/bash

function reverse(){
    for(( idx=${#array[@]}-1; idx>=0; idx--)); do
           echo "${array[idx]}"
    done    
}

function main(){
      cd $1
      array=( $(ls) )
      reverse
      

}
main $1
