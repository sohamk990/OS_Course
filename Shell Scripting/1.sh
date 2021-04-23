# Program Number: 1
# Student Name: SOHAM KOLHE 
# Register Number: IMT2018073
# Date: 10 Jan 2021

# Description: shell script to count the number of block device files in /dev directory.

#! /bin/bash
num="$(ls -Rl /dev | grep ^b | wc -l)"
echo $num