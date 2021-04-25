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

make -C $DIR
cp $DIR/push_swap $DIR/test
cp $DIR/checker $DIR/test

while read line
do
	./push_swap $line | ./checker $line &>/dev/null
	if [ $? -eq 1 ]; then
		echo "$line [$RET] [Error]"
		exit
	fi
	
	./push_swap $line | ./checker $line | grep KO
	KO=$?
	RET=$(./push_swap $line | wc -l)
	if [ $RET -gt 12 ] || [ $KO -eq 0 ]; then
		echo "$line [$RET] [KO]"
		exit
	else
		echo "$line [$RET] [OK]"
	fi
done < $1
