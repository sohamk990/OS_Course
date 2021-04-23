# Program Number: 14
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: shell script to print, “Good Morning/Afternoon/Evening based on the current system time.

#! /bin/bash
t=$(date +"%H")
if [ $t -lt 12 ]
then
    echo "Good Morning"
elif [ $t -le 17 ]
then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi