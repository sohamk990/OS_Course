# Program Number: 10
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: Shell script to backup a given directory to a given file name in your home directory. Both, the directory name and the backup file has to be passed as command line input respectively.

#! /bin/bash
bl="$HOME/"
if [ -d $1 ]
then
    tar -czvf "$2.tar.gz" $1
    mv "$2.tar.gz" $bl
    echo "Backup Created!!"
else 
    echo "Sorry Directory doesn't Exist"
fi