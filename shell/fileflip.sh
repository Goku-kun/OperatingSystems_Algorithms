echo $(tac $1) > temp_file
echo $(cat temp_file) | tr -s ' ' | tr ' ' '.'
