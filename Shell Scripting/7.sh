# Program Number: 7
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: Interactive file-handling shell program that offers the user choice of copying, removing, rename and ask required parameters.

#! /bin/bash
echo "1. Copy"
echo "2. Remove"
echo "3. Rename"
echo "Enter the command number you want to execute: "
read cmd
if [ $cmd -eq 1 ]
then
    echo "Enter the file you want to copy:"
    read fn
    while [ ! -f $fn ]
    do
        echo "File Doesn't Exist!"
        echo "Enter the file you want to copy:"
        read fn
    done
    echo "Enter the location where you want to copy:"
    read loc
    cp $fn $loc
elif [ $cmd -eq 2 ]
then
    echo "Enter the file you want to remove:"
    read fn
    while [ ! -f $fn ]
    do
        echo "File Doesn't Exist!"
        echo "Enter the file you want to remove:"
        read fn
    done
    rm $fn
elif [ $cmd -eq 3 ]
then
    echo "Enter Old File Name:"
    read on    
    while [ ! -f $on ]
    do
        echo "File Doesn't Exist!"
        echo "Enter Old File Name:"
        read on
    done
    echo "Enter New File Name:"
    read nn
    while [ -f $nn ]
    do
        echo "File Already Exist!"
        echo "Enter New File Name:"
        read nn
    done
    mv $on $nn
fi