read -p "Enter the number of rows : " a 
for((i=$a;i>=1;i--)); do
echo 
for((j=0;j<$i;j++)); do 
echo -n "$i"
done
done 
