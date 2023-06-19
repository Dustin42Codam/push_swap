#!/bin/bash

while read line
do
	./push_swap $line | ./checker $line
done < $1
