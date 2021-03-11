#!/bin/bash

ulimit -t 30
ulimit -v 8000000
counter=0
while read p; 
do 
    counter=$[$counter+1]
    printf "$counter: "
    ./main -astar $p; 
done < instances/15puzzle_instances.txt