#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: Wrong number of arguments!"
    echo "Usage:"
    echo "$> bash $0 <executable to test> <input to test>"
    echo "Example:"
    echo "$> bash $0 ./push_swap ./invalid_arg_string.txt"
	exit 1
fi

INPUT="$2"
while IFS= read -r LINE
do
	$1 $LINE
	RET=$?
	if [ $RET -ne 1 ]; then
		echo "Fail on input: $LINE"
	fi
done < "$INPUT"
