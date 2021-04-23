# Program Number: 15
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: 

#! /bin/bash
echo "Enter the file name:"
read fn
# fn=example
echo "1.For a given file, find all the lines containing our search pattern.​"
echo "2.List the lines not containing the search string​"
echo "3.Matching lines starting with a given pattern and ending in a second pattern​"
echo "4.Print a file starting from a certain line until to the end of file.​"
echo "5.Search a given pattern in a file and replace with a new pattern and display the file.​"
echo "6.Insert a given string at the beginning of each line of the file.​"
echo "7.Insert a given string at the end of each line of the file​"
echo "Enter the command number you want to execute: "
read cmd

if [ $cmd -eq 1 ]
then
    echo "Enter the pattern"
    read pt
    sed -n "/$pt/p" $fn
elif [ $cmd -eq 2 ]
then
    echo "Enter the pattern"
    read pt
    sed "/$pt/d" $fn 
elif [ $cmd -eq 3 ]
then
    echo "Enter the starting pattern"
    read spt
    echo "Enter the ending pattern"
    read ept
    sed -n "/^$spt.*$ept$/p" $fn
elif [ $cmd -eq 4 ]
then
    echo "Enter the starting line"
    read pt
    sed -n "$pt,\$p" $fn
elif [ $cmd -eq 5 ]
then
    echo "Enter the pattern to search"
    read ipt
    echo "Enter the pattern to replace"
    read rpt
    sed "s/$ipt/$rpt/g" $fn
elif [ $cmd -eq 6 ]
then
    echo "Enter the pattern to insert in begining of each line"
    read pt
    sed "s/^/$pt /" $fn
elif [ $cmd -eq 7 ]
then
    echo "Enter the pattern to insert in ending of each line"
    read pt
    sed "s/$/$pt /" $fn
fi