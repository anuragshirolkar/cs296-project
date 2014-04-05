#!bin/bash
HOME=./
SCR=$HOME/scripts
DAT=$HOME/data
BIN=$HOME/mybins
ITER=1500
RUN=150
rm -rf $DAT/g03_lab05data_random.csv
for i in $(seq 1 $ITER)
		do 
				for j in  $(seq 1 15)
			do 
			rand=$(($(($i-1))*RUN + $(( $(($RANDOM % $RUN)) + 1))))
			
			sed -n "$rand p" <$DAT/g03_lab05data_02.csv >>$DAT/g03_lab05data_random.csv  
done 
done
