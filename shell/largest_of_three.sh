read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
read -p "Enter number tres: " num3

avg=$(( (num1 + num2 + num3)/3 ))

echo "The average of $num1, $num2 and $num3 is $avg."

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
	echo "$num1 is the largest."

elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
	echo "$num2 is the largest."
else
	echo "$num3 is the largest."
fi
