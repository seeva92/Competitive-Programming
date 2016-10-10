from sys import stdin,stdout
from heapq import *
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
# stdout = open("E:\\1.txt","w")

# stdout.write(str(1000000)+'\n')
# for x in range(1000000):
# 	stdout.write(str(x)+" ")
# stdout.write("130\n")
def main():
	n = int(stdin.readline().strip())
	arr = list(map(int,stdin.readline().strip().split()))
	k = int(stdin.readline().strip())
	klst = []; i =0
	while i<n and i<k:
		klst.append((-arr[i],i))
		i+=1
	heapify(klst)
	stdout.write(str(-klst[0][0]))
	while i<n:
		heappush(klst,(-arr[i],i))
		while len(klst)>0 and klst[0][1]<(i-k+1):
			heappop(klst)
		stdout.write(" "+str(-klst[0][0]))
		i+=1

main()