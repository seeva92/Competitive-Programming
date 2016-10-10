from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	t = int(stdin.readline())
	for i in range(t):
		n = int(stdin.readline())
		a = [[0 for k in range(3)] for j in range(n)]
		b = [[0 for k in range(3)] for j in range(n)]
		for j in range(n):
			a[j] = list(map(int,stdin.readline().split()))
			if j == 0:
				b[j] = a[j]		
		for j in range(n):
			if j+1 < n:
				b[j+1][0] = a[j+1][0] + min(b[j][1], b[j][2])
				b[j+1][1] = a[j+1][1] + min(b[j][0], b[j][2])
				b[j+1][2] = a[j+1][2] + min(b[j][0], b[j][1])
		stdout.write(str(min(min(b[n-1][0],b[n-1][1]),b[n-1][2]))+'\n')
main()