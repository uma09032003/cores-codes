#Check if the search string is found in the parent array
fruits=("Apple" "Papaya" "Mango" "Orange" "Pineapple")
read -p "Enter fruit to search : " a 
for i in ${fruits[@]} 
do 
if [ $i == $a ]
then
echo "Fruit found !"
exit 
fi 
done 
echo -n "Fruit not found ! "
