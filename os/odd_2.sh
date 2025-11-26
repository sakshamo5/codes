sum=0
for ((i=1;i<=20;i=i+2))
do 
echo $i
((sum+=$i))
done

echo "Sum is: $sum"
