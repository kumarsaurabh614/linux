#!/bin/bash

log_add="/home/github_file/logs"

echo "files in logs directory are :"

list=$(ls $log_add)
echo $list


echo "Timestamp and Messages are : "


for file in $log_add/*
do
	 grep " " $file
	
done


