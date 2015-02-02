#!/bin/sh
#Assumptions: 
#1. if you have a line "abcd2515.32.32.2515abcd", then 15.32.32.251 is a valid IP
#2. if you have a line "10.1000.10.26.10.3289", then 00.10.26.10 and 10.26.10.32 are both valid IPs

FILES=./*
echo "$FILES"
for f in $FILES
do
    txt=""
    txt="$(cat $f | grep -E -o '(25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?)')"
    if [ "$txt" != "" ]
    then
        echo "$f"
    fi
done
