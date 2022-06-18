#SED in bash stands for Stream Editor which takes input text from any operates on it and returns the output to a specified output stream
#sed -i 'Nd' FileName is used to delete permanently from the source file
#sed 'Nd' FileName is used to delete any return the result without affecting the source file
#N stands for the number of line 
#sed '$d' FileName is used to delete the last line of file
#sed '/^$/d' Filename is used to remove the empty lines in the file 

sed -i '1d' Newfile.txt #To delete first line in the source file  
sed '3d' Newfile.txt     #To delete 3rd line  
sed '/^$/d' Newfile.txt  #To delete last line 
