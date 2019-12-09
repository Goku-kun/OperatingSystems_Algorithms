if [[ -d $1 ]];
then
    $(ls $1)
elif [[ -f $1 ]];
then
    $(more $1)
else
    echo "$1 is not valid"
fi
