echo "Enter a number:"
read $number
while [ $number -gt 0 ]
do echo $number
	$number=`expr $number - 1`
done
