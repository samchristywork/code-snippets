#!/bin/bash

# lerp $(date +%s) $(date +%s -d "7:00") $(date +%s -d "22:00") 0 100
# lerp $(date +%s) $(date +%s -d "7:58") $(date +%s -d "22:00") 18835 15000

x=$1
x0=$2
x1=$3
y0=$4
y1=$5

usage (){
  echo "Usage: $(basename $0) x x0 x1 y0 y1"
  exit 1
}

[ "$#" -eq "5" ] || usage

awk "BEGIN {
  print $y0+($x-$x0)*($y1-$y0)/($x1-$x0);
}" 2> /dev/null || usage
