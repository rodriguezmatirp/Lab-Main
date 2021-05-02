#!/bin/bash
#A
du -b

#B
du -ab

#C
wc -clL ./MyFile.txt 

#D
date

#E
date +"%D"

#F
ls -la (hidden files also)

#G
ls -R

#H
wc -cml ./MyFile.txt 

#I
wc -l ./MyFile.txt 

#J
cat ./assign3/tot.txt 

#K
more ./MyFile.txt

#L
more ~/OS/tot.txt

# M
echo "'less' is more efficient and easier to use than 'more'"

# N
head -5 verylong.seq

# O
grep -nR "length"

# P
diff 1.txt 2.txt 3.txt

# Q
head -7 verylong.seq > first-and-last
tail -7 verylong.seq >> first-and-last

# R
ls "*seq"

# S
find . -type -f -mtime -1 -ls

# T
w
who

# U
top

# V
finger $USER