#!/bin/bash

if [ $# -ne 4 ]; then
    echo "Error: Wrong number of arguments!"
    echo "Usage:"
    echo "$> bash $0 <range_min>-<range_max> <list size> <output path>"
    echo "Example:"
    echo "$> bash $0 0 200 100 /home/project"
    echo "=> Generates 100 unique random values within range 0-200 at /home/project"
	exit 1
fi

shuf -i $1-$2 -n $3 | tr '\n' ' ' > $4
