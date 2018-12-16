#!/bin/bash

function filter {
   
    echo "HI"
}

function average {

 # FILECNT=0
 # TOTFILESIZE=0
 # for file in $files ;do
    # FILESIZE=$(du "$file")
   #  ((FILECNT++))
  #   TOTFILESIZE=$(( TOTFILESIZE + FILESIZE ))
 # done
 # AVE=($TOTFIZESIE/$FILECNT)
 # echo AVE
  expr $(du -Ss | cut -f1 ) / $(find /path/to/CS288 -maxdepth 1 -type f | wc -1)
}

function main { 
  
  files=$( ls $1 )
  average
}

main $1
