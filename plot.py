import matplotlib.pyplot as plt
import subprocess
import sys
from timeit import timeit

##subprocess.run(["ls", "-l"])
support_thresholds = [90,50,25,10,5,1]
apriori_times = []
fp_times = []
filename = sys.argv[1]

def run_system_call(code_type,support,filename):
    if code_type =="fptree":
        subprocess.run(["./fptree",str(support),filename,"filename"+".txt"])
    if code_type == "apriori":
        subprocess.run(["./apriori",str(support),filename,"filename"+".txt"])


def measure_time_function(func, *args, **kwargs):
    def time_function():
        return func(*args, **kwargs)
    return time_function
### Apriori time ###
for support in support_thresholds:
    time_function = measure_time_function(run_system_call, "apriori",support,filename)
    apriori_times.append(timeit(time_function, number=1))

### fptree time ###
for support in support_thresholds:
    time_function = measure_time_function(run_system_call, "fptree",support,filename)
    fp_times.append(timeit(time_function, number=1))


print(fp_times)
print(apriori_times)



plt.plot(support_thresholds,apriori_times,'-b',label = '-Apriori')
plt.plot(support_thresholds,fp_times,'-r',label = '-Fptree')
plt.xlabel('Support thresholds %')
plt.ylabel('Running time (seconds)%')
plt.legend(loc='upper right')
plt.title('Comparision of thresholds vs running time for apriori and fptree')
plt.savefig(filename+"_plot.png")
##plt.show()


