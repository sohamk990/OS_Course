# Program Number: 13
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: shell script to print a multiplication table.​

#! /bin/bash
echo "Enter the number:"
read n

echo "Enter the range:"
read r

i=1

while [ $i -le $r ]
do
    echo "$n x $i = $((i*n))"
    i=$((i+1))
done