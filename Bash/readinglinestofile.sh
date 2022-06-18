#Write a Bash Script to read 10 lines from Stdin and write it into a file 

n=10
while [ $n -gt 0 ]; 
do 
read -p "Enter line : " a 
echo "$a" >> Newfile.txt
((n--))
done 
