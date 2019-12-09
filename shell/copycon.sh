if [  $# -ep 0  ]
then
        echo "No file specified!"
        exit 1
fi
for i in $* 
do
        $file=$i
        cat >$file
        echo "\t 1 file(s) copied"
done
