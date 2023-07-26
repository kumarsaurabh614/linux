#!/bin/bash


for i in {1..8};
do
	for j in {1..8};
	do
		S=$(((i+j)%2))
		if [ $S -eq 0 ];
		then
			echo -ne "\e[47m "
		else
			echo -ne "\e[40m "
		fi

	echo  -ne "  \e[0m"
done
echo
done
