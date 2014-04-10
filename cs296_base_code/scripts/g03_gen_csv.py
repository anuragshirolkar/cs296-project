import sys
import subprocess
import re
from random import randint
import csv
import random
f=open('./data/g03_data.csv','w')
f1=open('./data/g03_data_rand.csv','w')
c1=500
c2=10
for i in range(1,c1+1):
	for j in range (1,c2+1):
		call=['./mybins/cs296_03_exe',str(i)]
		popen = subprocess.Popen(call, stdout=subprocess.PIPE)
		output = popen.stdout.read()
		fin=str(output)
		req = re.findall(r'[0-9]+(?:[.][0-9]+)?', fin)
		f.write(req[0]+','+str(j)+','+req[1]+','+req[2]+','+req[3]+','+req[4]+','+req[5]+'\n')
f.close()
f=open('./data/g03_data.csv')
reader=csv.reader(f, delimiter=',')
a=[]
c_rand=5

for i in range(1,c1+1):
	b=random.sample(range(1,c2+1),c_rand)
	for k in range (c_rand):
		a.append((i-1)*c2+b[k])
		
#print(len(a))
i=1
#print(a)
for row in reader:
	if i in a:
		f1.write(','.join(row)+'\n')
	i+=1
#print(i)

