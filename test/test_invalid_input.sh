#!/bin/bash

DIR="/home/hektor/Projects/push_swap/mygit"

if [ $# -ne 1 ]; then
    echo "Error: Wrong number of arguments!"
    echo "Usage:"
    echo "$> bash $0 <input file>"
    echo "Example:"
    echo "$> bash $0 ./some_file"
	exit 1
fi

make -C $DIR &>/dev/null
cp $DIR/push_swap $DIR/test
cp $DIR/checker $DIR/test

while read line
do
	./push_swap $line &>/dev/null
	RET_PS=$?
	./checker $line &/dev/null
	RET_CH=$?
	if [ $RET_CH -ne 1 ] || [ $RET_PS -ne 1 ]; then
		echo "$line failed to exit with error!"
		exit
	fi
done < $1
