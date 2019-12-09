#!/bin/bash

echo "Enter a number:"
read n
declare -i counter=0
while [ $counter -ne $n ]
do 
	echo $counter
	counter=$(( counter+1 ))
done
