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

echo "Checking for leaks..."

while read line
do
	echo "./push_swap $line"
	valgrind --leak-check=full --track-origins=yes ./push_swap $line 2>&1 | grep "no leaks"
	RET=$?
	if [ $RET -ne 0 ]; then
		echo "./push_swap $line - leaks memory!"
		break
		exit
	fi
	echo "./checker $line"
	valgrind --leak-check=full --track-origins=yes ./checker $line 2>&1 | grep "no leaks"
	RET=$?
	if [ $RET -ne 0 ]; then
		echo "./checker $line - leaks memory!"
		break
		exit
	fi
done < $1

echo "done!"
