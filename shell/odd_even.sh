echo "Enter a numner:"
read number
result=`expr $number % 2`
if [ $result -eq 0 ] 
then
	echo "Number is even"
else
	echo "Number is odd"
fi
