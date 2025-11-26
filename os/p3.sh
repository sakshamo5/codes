echo "Enter number 1:"
read a
echo "Enter number 2:"
read b
echo "Enter number 3:"
read c

if [ "$a" -ge "$b" ] && [ "$a" -ge "$c" ]
then
echo "The greatest number is: $a"
elif [ "$b" -ge "$a" ] && [ "$b" -ge "$c" ]
then
echo "The greatest number is: $b"
else
echo "The greatest number is: $c"
fi

