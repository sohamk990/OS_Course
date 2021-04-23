# Program Number: 9
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: script that accepts a file name starting and ending line numbers as arguments and displays all the lines between the given line numbers. ​

#! /bin/bash
echo "Enter file name:"
read fn
echo "Enter starting line number:"
read sn
echo "Enter ending line number:"
read en
head $fn -n $en | tail +$sn