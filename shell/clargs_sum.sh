#!/bin/bash

for i in $*
do
	let sum=$(( sum + i ))
done

echo $sum
