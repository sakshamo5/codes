echo "Please enter your marks in subject 1"
read a
echo "Please enter your marks in subject 2"
read b
echo "Please enter your marks in subject 3"
read c
echo "Please enter your marks in subject 4"
read d
echo "Please enter your marks in subject 5"
read e

((sum = $a+$b+$c+$d+$e))
((marks = $sum/5))

echo "Average marks $marks"

if [ $marks -ge 90 ]
then 
echo "Grade is A"
elif [ $marks -ge 75 ] && [ $marks -lt 90 ]
then
echo "Grade is B"
elif [ $marks -ge 60 ] && [ $marks -lt 75 ]
then 
echo "Grade is C"
elif [ $marks -ge 33 ] && [ $marks -lt 60 ]
then 
echo "Grade is D"
elif [ $marks -lt 33 ]
then 
echo "Grade is F"
else
echo "error"
fi
