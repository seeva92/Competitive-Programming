import sys
sys.stdin = open("/Users/seeva92/Workspace/Contests/1.txt", "r")
sys.stdout = open("/Users/seeva92/Workspace/Contests/2.txt", "w")
colors = list(0 for i in range(0,107))
def compute():
	n = int(input())
	for i in map(int,input().split()):
		colors[i]+=1

	res = sum(int(i/2) for i in colors)
	print(res)

compute()

