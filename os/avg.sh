avg()
{
average=$(($1 + $2 + $3))
echo $((average/3))
}

avg $1 $2 $3
