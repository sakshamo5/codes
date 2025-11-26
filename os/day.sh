echo "enter the number of the day"
read a
case $a in 
1) echo "Its Monday";;
2) echo "Its Tuesday";;
3) echo "Its Wednesday";;
4) echo "Its Thursday";;
5) echo "Its Friday";;
6) echo "Its Saturday";;
7) echo "Its Sunday";;
*) echo "Invalid day";;
esac
