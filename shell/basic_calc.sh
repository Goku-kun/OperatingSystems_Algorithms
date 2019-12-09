echo "1> Addition"
echo "2> Subraction"
echo "3> Multiplication"
echo "4> Division"
read -p "Enter your choice: " choice

case $choice in
	1)
		echo $(( $1+$2 ))
		;;
	2)
		echo $(( $1 - $2 ))
		;;
	3)
		echo $(( $1 * $2 ))
		;;
	4)
		echo $(( $1 / $2 ))
		;;
	*)
		echo "Invalid Input"
		;;
esac
