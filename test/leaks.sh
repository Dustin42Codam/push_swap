#!/bin/bash

DIR="/home/hektor/Projects/push_swap/mygit"
INPUT=$DIR/test/leaks_test_input.txt

make -C $DIR &>/dev/null
cp $DIR/push_swap $DIR/test
cp $DIR/checker $DIR/test

echo "Checking for leaks..."

while read line
do
	echo "$line"
	$line 2>&1 | grep "no leaks"
done < $INPUT

echo "done!"
