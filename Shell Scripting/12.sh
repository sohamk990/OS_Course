# Program Number: 12
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: Write a script according to the following criteria:​
    # a) If you search for the IIT the output is NIT​
    # b) If you search for NIT the output is IIT​
    # c) If you search any other keyword or not give any input, the output is STDERR should be displayed.​

#! /bin/bash
echo "Enter the search Keyword:"
read search
if [ "$search" == "IIT" ]
then
    echo "NIT"
elif [ "$search" == "NIT" ]
then
    echo "IIT"
else
    echo "STDERR"
fi