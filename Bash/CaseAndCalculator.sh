read -p "Enter Variable 1 : " a 
read -p "Enter Variable 2 : " b 
read -p "Enter choice : (+,-,/,*,%) : " c 
case $c in
"+") echo "Sum is $[$a+$b]"
;;
"-") echo "Difference is $[$a-$b]"
;;
"*") echo "Product is $[$a*$b]"
;;
"/") echo "Quotient is $[$a/$b]"
;;
"%") echo "Remainder is $[$a%$b]"
;;
*) echo "No Valid Option"
esac 
