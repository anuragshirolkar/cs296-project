#!bin/bash
HOME=./
SCR=$HOME/scripts
DAT=$HOME/data
BIN=$HOME/mybins
RUN=150
ITER=1500
rm -rf $DAT/g03_lab05data_02.csv
for j in $(seq 1 $ITER)
	do 
		for i in  $(seq 1 $RUN)
		do
#a=$(sed -n 's/[a-zA-Z :][a-zA-Z :]*\([0-9.][0-9.]*\)[a-z ]*/\1,/p' ${DAT}/g03-$j-$i | tr ',\s' ',' |sed -e "s/,\+/,$j,/") 
	./$BIN/cs296_03_exe $(seq 1 $((j-1)))|sed 's/[^0-9.]*//g' |tr '\n' ','|sed 's/,,/,/'|sed -e "s/$j,/$j,$i,/"|sed -e :a -e '/^\n*$/{
$d;N;ba' -e '}' | sed -e '$s/,$/\n/' >>$DAT/g03_lab05data_02.csv
#echo $a >>$DAT/g03_lab05data_02.csv
		done
		done
