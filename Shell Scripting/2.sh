# Program Number: 2
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: shell program that checks the number of command line arguments and echoes an error message 
# if there are not exactly three arguments or echoes the arguments themselves if there are three.

#! /bin/bash
if [ $# -eq 3 ]
then
    echo $@
else
    echo "ERROR!!"
fi