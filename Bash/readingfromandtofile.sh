#Reading all the lines from one file and print to another file using while loop
while read -a ar ; do 
echo "${ar[0]}" >> Newfile.txt 
done < Myfile.txt
