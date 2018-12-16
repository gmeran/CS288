#!/bin/bash
echo "enter number of element in the array"
read n
echo "enter numbers into array"
for((i=0; i<n; i++ ));do
   read nums[$i]
done

for(( i=1; i<n; i++));do
    j=$i-1
    temp=${nums[$i]}
    while((j>=0 && nums[j]>temp));do
          nums[$j+1]=${nums[$j]}
          j=$j-1
    done
    nums[j+1]=$temp
done

echo "sorted array"
for((i=0; i<n; i++));do
   echo ${nums[$i]}
done
