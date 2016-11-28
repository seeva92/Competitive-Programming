from sys import stdin,stdout
from math import *
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def compute(T):
	l = 0; r = 1e18; mid = 0;
	while(l<r):
		mid = (l+r+1)/2
		print(mid)
		if(mid*(log(mid)/log(3))<= T):
			l = mid
		else:
			r = mid - 1
	stdout.write(str(r))

def main():
	t = int(stdin.readline()) 
	for _ in range(t):
		stdin.readline()
		T = float(stdin.readline())
		compute(T)

main()