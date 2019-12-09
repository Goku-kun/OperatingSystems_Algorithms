for i in $*
do
	let sum=$(( sum + i ))
done
if $(( sum % 2)) -eq 0
then
	echo "Sum is Even."
fi
