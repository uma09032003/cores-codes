#Simlple bash program to print Alphabet Half Pyramid
#Assume the input given is within the range of the alphabets

read -p "Enter the number of lines " a
k=65
for((i=0;i<$a;i++)); do
echo 
for((j=0;j<=$i;j++)); do
printf \\$(printf '%03o' $[$k+$j])
done
done 
