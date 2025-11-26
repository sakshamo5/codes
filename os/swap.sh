

swap() {
temp=$num1
num1=$num2
num2=$temp
}

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 num1 num2"
  exit 1
fi

num1=$1
num2=$2

echo "Before swapping: num1=$num1, num2=$num2"

swap

echo "After swapping: num1=$num1, num2=$num2"

