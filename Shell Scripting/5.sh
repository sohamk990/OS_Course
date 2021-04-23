# Program Number: 5
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: Script that uses find to look for a file and echo a suitable message if the file is not found.

#! /bin/bash
echo "Enter the file name you want to find"
read fn
cnt=$(find $HOME -name $fn | wc -l)
if [ $cnt -eq 0 ]
then
    echo "File Not Found!"
else
    echo "$(find $HOME -name $fn)"
fi