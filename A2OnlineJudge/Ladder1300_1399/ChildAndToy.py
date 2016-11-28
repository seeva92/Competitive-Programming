from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
n,m = map(int,stdin.readline().split())
v = list(map(int,stdin.readline().split()))
g = [list() for i in range(n)]
for i in range(m):
	x,y = map(int,stdin.readline().split())
	g[x-1].append(y-1)
	g[y-1].append(x-1)
def main():
	res = 0
	vis = [False for i in range(n)]
	q = []; q.append(0); vis[0] = True
	mp = dict()
	for i,_ in enumerate(g):
		for j in g[i]:
			if mp.get((i,j),0) == 0 and mp.get((j,i),0)==0:			
				res += min(v[i],v[j])
				mp[(i,j)] = 1; mp[(j,i)] = 1			
	stdout.write(str(res))
	# stdout.write("wow")
main()