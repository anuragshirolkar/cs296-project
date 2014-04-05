#!bin/bash
HOME=./
SCR=$HOME/scripts
DAT=$HOME/data
BIN=$HOME/mybins
ITER=1500
RUN=150
for i in $(seq 1 $RUN)
do 
	for j in  $(seq 1 $ITER)
	do
    ./$BIN/cs296_03_exe $(seq 1 $((j-1)))  >$DAT/g03-$j-$i.txt;
	done
done
