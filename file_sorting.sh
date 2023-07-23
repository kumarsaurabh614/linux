#!/bin/bash


echo "input directory name"
read folder
if [ ! -d "$folder" ]; then
	echo "folder not found"
	exit 1
fi
ls_command=$(ls $folder)
echo files in $folder are
echo $ls_command


ls_command_sorted=$(ls $folder|sort)
echo sorted file orders are :
echo $ls_command_sorted


echo making a new directory

new_folder=$(mkdir "$folder/sorted")
echo $new_folder

echo new folder created

echo moving files to new sorted folder
count=0
for element in $ls_command_sorted
do
	cp "$folder/$element" "$folder/sorted"
	let count++
done 

echo $count files moved successfully
