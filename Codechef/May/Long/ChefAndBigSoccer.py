# import sys
# sys.stdin = open("/home/shiva/Learning/1.txt","r")
# sys.stdout = open("/home/shiva/Learning/3.txt","w")
from sys import stdin,stdout
mod = 10**9+7
t = int(stdin.readline().strip())
f = [[0]*1007 for i in range(1007)]

for x in range(t):
	N,M,s = map(int,stdin.readline().strip().split())
	s-=1
	strength = list(i for i in map(int,stdin.readline().strip().split()));
	for j in range(M+1):
		for i in range(N):
			if j==0:
				f[i][j] = 1 if i==s else 0
			else:
				result = 0
				if (i-strength[j-1]) >= 0: 
					result+= f[i-strength[j-1]][j-1]
				if (i+strength[j-1]) < N: 
					result+= f[i+strength[j-1]][j-1]
				f[i][j] = result
					
	for i in range(N):
		stdout.write(str(f[i][M]%mod)+" ")
	stdout.write("\n")
