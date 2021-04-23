# Program Number: 1
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073

# Description: 

#! /bin/bash
echo "Enter file name:"
read fn
# fn=employee.txt
echo "1.Display a given file."
echo "2.Print the lines which match with a given pattern."
echo "3.Print only a specific field in the file."
echo "4.Format a given file with Name, Designation, Department and Salary headings and at the end of a file print Report Generated."
echo "5.Find the employees, who has id > 200"
echo "6.Find the list of employees in a Technology Department."
echo "7.Print the number of employees in Technology Department."
echo "Enter the command number you want to execute: "
read cmd

if [ $cmd -eq 1 ]
then
    awk "{print;}" $fn
elif [ $cmd -eq 2 ]
then
    echo "Enter the pattern"
    read pt
    awk "/$pt/ {print;}" $fn
elif [ $cmd -eq 3 ]
then
    echo "Enter the column number from 1 to 5"
    read ln
    awk '{print $k }' k=$ln $fn
elif [ $cmd -eq 4 ]
then 
    awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";} {print $2,"\t",$3,"\t",$4,"\t",$NF;} END{print "Report Generated\n--------------"; }' $fn
elif [ $cmd -eq 5 ]
then
    awk '{ if ( $1 > 200 ) print $0 }' $fn
elif [ $cmd -eq 6 ]
then
    awk '{ if ( $4 == "Technology" ) print $0 }' $fn
elif [ $cmd -eq 7 ]
then
    awk '{ if ( $4 == "Technology" ) print $0 }' $fn | wc -l
fi