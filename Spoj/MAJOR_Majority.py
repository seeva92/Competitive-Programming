from sys import stdin,stdout
from collections import *
# stdin = open("/home/shiva/Learning/1.txt","r")
# stdout = open("/home/shiva/Learning/2.txt","w")

def main():
	for a in range(int(stdin.readline().strip())):
		n = int(stdin.readline())
		arr = list(map(int,stdin.readline().strip().split()))
		pos = [0]*1001
		neg = [0]*1001
		for i in arr:
			if i<0:
				neg[-1*i]+=1
			else:
				pos[i]+=1

		val = 0; ii=0; vali = -1;
		for i in pos:
			if i>val:
				val = i
				vali = ii
		
			ii+=1
		if flag!=-1:
			stdout.write('YES '+str(flag)+'\n')
		else:
			stdout.write('NO\n')

main()