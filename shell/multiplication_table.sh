#!/bin/bash

read -p "Enter a number: " number

i=0

while [ $i -le 10 ]
do
	echo "$number X $i = $(( number * i ))"
	i=$(( i + 1 ))
done
