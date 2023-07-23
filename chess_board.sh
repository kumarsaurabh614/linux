#!/bin/bash


for i in {1..8};
do
	for j in {1..8};
	do
		S=$(((i+j)%2))
		if [ $S -eq 0 ];
		then
			echo -n "0 "
		else
			echo -n "1 "
		fi
	done
	echo ""
done
