#!/bin/bash
DIR="/usr/bin"
cd $DIR
array=$(ls)
echo ${#array[@]}
count=0
currentPrefix=""
for file in $array; do
  prefix=${file:0:1}
  if [ "$prefix" != "$currentPrefix" ]; then
     echo "$currentPrefix $count"
     currentPrefix=$prefix
     count=0
  fi
  count=$((count+1))
done
echo "$currentPrefix $count"



