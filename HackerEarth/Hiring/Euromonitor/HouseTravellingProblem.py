from sys import stdin,stdout
from operator import itemgetter
# stdin = open("in.txt","r")
# stdout = open("out.txt","w")
def findSet(i):
	if parent[i] == i:
		return i
	parent[i] = findSet(parent[i])
	return parent[i]
def uni(x,y):
	xt = findSet(x); yt = findSet(y)
	if xt != yt:
		if rank[xt] < rank[yt]:
			parent[xt] = yt
		else:
			parent[yt] = xt
			if rank[xt] == rank[yt]:
				rank[xt]+=1		
		return True
	return False

N = int(stdin.readline())
pts = tuple(tuple(map(int,stdin.readline().split())) for _ in range(N))

mat = tuple(tuple(map(int,stdin.readline().split())) for _ in range(N))	
cnt = N-1
parent = [i for i in range(N)]
rank = [0] * N
edges = sorted([((((pts[i][0]-pts[j][0])*(pts[i][0]-pts[j][0]))+((pts[i][1]-pts[j][1])*(pts[i][1]-pts[j][1]))),(i,j)) for i in range(N) for j in range(i+1,N) if i<j and mat[i][j]==1],reverse=True,key=itemgetter(0))

dist = 0
for i in edges:
	if uni(i[1][0],i[1][1]):
		dist+= i[0]			
		cnt-=1
		if cnt == 0:
			break
if cnt == 0:
	stdout.write(str(dist)+'\n')
else:
	stdout.write("-1\n")
			
