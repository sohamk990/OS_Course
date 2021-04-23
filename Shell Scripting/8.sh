# Program Number: 8
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: shell script that takes a login name as command – line argument and reports when that person logged in. ​

#! /bin/bash
if [ $(last -R $1 | wc -l) -gt 2 ]
then 
    log=$(last -R $1 | head -n 1 | awk '{print $3,$5,$4,$6}')
    echo $log
else 
    echo "User Doesn't Exist"
fi