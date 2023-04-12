#Write a Bash Script to add a SIngle User and update his password credentials 
#!/bin/bash
read -p "Enter Username" user
if sudo useradd $user; then
  if sudo passwd $user; then
  	echo "User Updation Successful"
  else
  	echo "Error in the Password entered"
  fi
else
  echo -e "Error in accepting Username\n Retry or Revisit Code"
fi 
