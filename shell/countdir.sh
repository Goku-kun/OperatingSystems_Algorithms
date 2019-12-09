echo "Number of files in $1:"
c=$(find $1 | wc -l)
c=$(( c - 1 ))
echo $c
echo "$1 contents:"
ls -l $1
