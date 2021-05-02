#!/bin/bash
#A
cd OS

#B
mkdir assign3

#C
touch Test_1.txt Test_2.txt Test_1-1.txt Test_2-1.txt 
Test_1-2.xtxt Test_2-2.xtxt Test_1-1.bak Test_2-2.bak File_1.bat

#D
ls

#E
ls | grep '.txt$'

#F
ls | grep '*t'

#G
cp $(ls | grep 't_1') assign3

#H
cd assign3
ls

#I
ls - grep 'Test_2'

#J
cat $(ls | grep 'Test_1') >> tot.tx

#K
find . -maxdepth 1 -type f | wc -l

#L
ls > FileList.txt

#M
cp ~/a* ./

#N
rm $(ls ??)

#O 
rm $HOME/folder -r

# P
cd /