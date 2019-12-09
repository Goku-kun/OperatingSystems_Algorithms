read -p "Enter year to check: " year
(( !(year % 4) && ( year % 100 || !(year % 400) ) )) &&
echo "leap year" || echo "not a leap"
