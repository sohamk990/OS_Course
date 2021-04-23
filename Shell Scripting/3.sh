# Program Number: 3
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: The shell program will create a new file associated with each command line argument and echo a message that notifies the user as each file is created. ​

#! /bin/bash
for a in $@
do
    if [ ! -f $a ]
    then
        touch $a
        echo "File $a created"
    else
        echo "File $a Already exsit"
    fi
done