isOdd()
{
if (($1%2!=0)) 
then
echo $1
fi
}



for ((i =1; i<=20;i++))
do
isOdd $i
done


