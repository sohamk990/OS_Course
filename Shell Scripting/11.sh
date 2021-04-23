# Program Number: 11
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: script to check how much space is used by each directory of a given file system. The name of the file system has to be provided from the command line parameter

#! /bin/bash
echo "$(du -h $1)"