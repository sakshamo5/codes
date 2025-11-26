echo "enter first number"
read a
echo "enter second number"
read b

echo "choose operator: +-*/"
read op
case $op in 
+) echo "Result = $((a+b))";;
-) echo "Result = $((a-b))";;
\*) echo "Result = $((a*b))";;
/) echo "Result = $((a/b))";;
*) echo "Invalid operation";;
esac
