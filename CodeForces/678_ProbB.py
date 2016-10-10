from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
from functools import reduce
from operator import mul
import datetime
import calendar
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
def main():
	stdout.write(str(gcd(15,30)))
    # stdout.write("wow")
    # year = int(stdin.readline().strip())
    # first = calendar.weekday(year,1,1)
    # for year in range(1000,2051):
        # first = calendar.weekday(year,1,1)
        # for y in range(year+1,100001):
            # if first == calendar.weekday(y,1,1) and calendar.isleap(first) == calendar.isleap(y):
                # stdout.write(str(y)+'\n'); break
    # first = datetime.datetime(2016,6,13)
    # second = datetime.datetime(2017,6,13)
    # stdout.write(str(calendar.months[calendar.weekday(2017,6,13)]))
    # stdout.write(str(365%7))
    # stdout.write(str((second-first).days))
main()
