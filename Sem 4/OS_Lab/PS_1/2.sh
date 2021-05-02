#!/bin/bash
#A
cd OS

#B
mkdir assign2

#C
touch MyFile.txt
echo "Favorite Movie" > MyFile.txt
echo "Favorite Food" >> MyFile.txt

#D
cat MyFile.txt

#E
cp MyFile.txt assign1/
mv assign1/MyFile.txt assign1/t_1.txt

#F
cd assign1

#G
cp t_1.txt t_2.txt

#H 
ls

#I
cp t_1.txt ../assign2/

#J
ls

#K
rm t_1.txt

#L
ls