# Program Number: 6
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: script which will give 4 choices to the user 1. ls   2. pwd  3. who 4. exit and execute the command as per the users choice.​

#! /bin/bash
echo "Enter the command number you want to execute: "
echo "1. ls"
echo "2. pwd"
echo "3. who"
echo "4. exit"
read cmd
if [ $cmd -eq 1 ]
then
    echo $(ls)
elif [ $cmd -eq 2 ]
then
    echo "$(pwd)"
elif [ $cmd -eq 3 ]
then
    echo "$(who)"
elif [ $cmd -eq 4 ]
then
    echo "Bye!"
fi