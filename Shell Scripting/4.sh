# Program Number: 4
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: Create a directory called .recyclebin in your home directory and will move all of the files you delete into the .recyclebin directory. Take filename using comman line arguments

#! /bin/bash
location="$HOME/.recyclebin"
if [ ! -d $location ]
then
    mkdir $location
fi

for file in $@
do
    if [ -f $file ]
    then
        mv $file "$location"
        echo "$file Removed"
    else 
        echo "$file Doen't Exist"
    fi
done