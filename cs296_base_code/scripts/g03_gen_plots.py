import numpy as np
import matplotlib.pyplot as plt
import csv
from matplotlib.font_manager import FontProperties

'''############################################################################
   Reading CSV Data
#############################################################################'''

max_reruns=10
max_rand_reruns=5

datafile = open('./data/g03_data.csv', 'r')
datareader = csv.reader(datafile)
iteration=[]
rerun=[]
step=[]
collision=[]
velocity=[]
position=[]
loop=[]
for row in datareader:
    iteration.append(int(row[0]))
    rerun.append(int(row[1]))
    step.append(float(row[2]))
    collision.append(float(row[3]))
    velocity.append(float(row[4]))
    position.append(float(row[5]))
    loop.append(float(row[6]))


'''############################################################################
   Creating Average over reruns
#############################################################################'''

ln = len(iteration)
avg_ln = ln//max_reruns
avg_iteration=[]
avg_step=[]
avg_collision=[]
avg_velocity=[]
avg_position=[]
avg_loop=[]
for i in range(avg_ln):
    avg_iteration.append(i)
    avg_step.append(sum(step[i*max_reruns:i*max_reruns+max_reruns])/max_reruns)
    avg_collision.append(sum(collision[i*max_reruns:i*max_reruns+max_reruns])/max_reruns)
    avg_velocity.append(sum(velocity[i*max_reruns:i*max_reruns+max_reruns])/max_reruns)
    avg_position.append(sum(position[i*max_reruns:i*max_reruns+max_reruns])/max_reruns)
    avg_loop.append(sum(loop[i*max_reruns:i*max_reruns+max_reruns])/max_reruns)

'''############################################################################
   Graph 01
#############################################################################'''

mx=max([max(avg_step),max(avg_loop)])
max_loop=max(avg_loop)
min_loop=min(avg_loop)
fontP = FontProperties()
fontP.set_size('small')
plt.bar(avg_iteration, avg_step, color='y', label='avg step time bar graph')
plt.plot(avg_iteration, avg_loop, label='avg loop time line graph')
plt.plot([avg_iteration[0],avg_iteration[-1]], [max_loop,max_loop], 'b--', label='max of avg loop time', color='r')
plt.plot([avg_iteration[0],avg_iteration[-1]], [min_loop,min_loop], 'b--', label='min of avg loop time', color='g')
plt.legend(prop=fontP)
plt.xlabel('Iteration value')
plt.ylabel('Time')
x1,x2,y1,y2 = plt.axis()
plt.axis((x1,x2,0,mx*1.3))
plt.suptitle('Graph 01')
plt.savefig('./plots/g03_plot01.png')
plt.clf()

'''############################################################################
   Graph 02
#############################################################################'''

sum_col_vel_pos=[]
for i in range(len(avg_iteration)):
    sum_col_vel_pos.append(avg_collision[i]+avg_velocity[i]+avg_position[i])
mx = max([max(sum_col_vel_pos), max(avg_step)])
plt.plot(avg_iteration, avg_step, label='avg step time')
plt.plot(avg_iteration, avg_collision, label='avg collision time')
plt.plot(avg_iteration, avg_velocity, label='avg velocity time')
plt.plot(avg_iteration, avg_position, label='avg position time')
plt.plot(avg_iteration, sum_col_vel_pos, label='sum of avg col, vel, pos')
plt.legend(prop=fontP)
x1,x2,y1,y2 = plt.axis()
plt.axis((x1,x2,0,mx*1))
plt.xlabel('Iteration value')
plt.ylabel('Time')
plt.suptitle('Graph 02')
plt.savefig('./plots/g03_plot02.png')
plt.clf()

'''############################################################################
   Graph 03
#############################################################################'''

std_step=[]
for i in range(avg_ln):
    std_step.append(np.std(step[i*max_reruns:i*max_reruns+max_reruns]))

plt.errorbar(avg_iteration, avg_step, yerr=std_step, label='avg step time with error', ecolor='r')
plt.legend(prop=fontP)
plt.xlabel('Iteration value')
plt.ylabel('Time')
plt.suptitle('Graph 03')
plt.savefig('./plots/g03_plot03.png')
plt.clf()

'''############################################################################
   Graph 04
#############################################################################'''

roll_no=16
width=0.01
max_step_roll=max(step[roll_no*max_reruns:roll_no*max_reruns+max_reruns])
no_intervals=int(max_step_roll/width)+1
intervs=[]
for i in range(no_intervals):
    intervs.append(i*width)
bins=[0]*no_intervals
cumul=[0]*no_intervals
sm=0
for i in range(roll_no*max_reruns, roll_no*max_reruns+max_reruns):
    interval = int(step[i]/width)
    bins[interval] += 1
for i in range(no_intervals):
    sm+=bins[i]
    cumul[i]=sm
mx=max(cumul)
plt.bar(intervs, bins, color='y', label='frequency', width=width)
plt.plot(intervs, cumul, label='cumulative frequency')
plt.legend(prop=fontP)
plt.xlabel('Interval')
plt.ylabel('Frequency')
x1,x2,y1,y2 = plt.axis()
plt.axis((x1,x2,0,mx*1.2))
plt.suptitle('Graph 04')
plt.savefig('./plots/g03_plot04.png')
plt.clf()


'''############################################################################
   Reading Random CSV Data
#############################################################################'''

datafile = open('./data/g03_data_rand.csv', 'r')
datareader = csv.reader(datafile)
iteration_rand=[]
rerun_rand=[]
step_rand=[]
for row in datareader:
    iteration_rand.append(int(row[0]))
    rerun_rand.append(int(row[1]))
    step_rand.append(float(row[2]))

ln_rand = len(iteration_rand)
avg_ln_rand = ln//max_rand_reruns
avg_iteration_rand=[]
avg_step_rand=[]
for i in range(avg_ln):
    avg_iteration_rand.append(i)
    avg_step_rand.append(sum(step[i*max_rand_reruns:i*max_rand_reruns+max_rand_reruns])/max_rand_reruns)



'''############################################################################
   Graph 05
#############################################################################'''

plt.scatter(avg_iteration, avg_step,label='avg step time', color='y', marker='.')
coefs = np.lib.polyfit(avg_iteration, avg_step, 1)
fit = np.lib.polyval(coefs, avg_iteration)
plt.plot(avg_iteration, fit, 'b--',label='best fit line', color='b')

plt.scatter(avg_iteration_rand, avg_step_rand,label='avg step time random', color='g', marker='x')
coefs_rand = np.lib.polyfit(avg_iteration_rand, avg_step_rand, 1)
fit_rand = np.lib.polyval(coefs_rand, avg_iteration_rand)
plt.plot(avg_iteration_rand, fit_rand, 'b--',label='best fit line for random', color='r')

plt.legend(prop=fontP)
plt.xlabel('Iteration value')
plt.ylabel('Time')
plt.suptitle('Graph 05')
plt.savefig('./plots/g03_plot05.png')
plt.clf()
plt.close()
