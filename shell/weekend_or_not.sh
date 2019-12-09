if [ $(date+%u) -gt 5 ]
then
        echo "Weekend!"
else
        echo "Not a Weekend."
fi
