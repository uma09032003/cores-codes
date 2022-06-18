#Read an array separated by custom input character

# This document has 2 programs where the answer mentioned in the heading is available in the second line *****


#Program 1 = Internal File Descriptor Demonstration
read -a ar 
IFS="-"
i="${#ar[@]}"
echo "$i"
IFS="-"
read -a ar
i="${#ar[@]}"
echo "$i"


#Program 2 = Actual Needed Script 
read -p "Enter the separating character of the input " s 
IFS="$s"
read -a ar 
i="${#ar[@]}"
echo "$i"
