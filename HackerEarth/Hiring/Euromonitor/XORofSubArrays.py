from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	T = int(stdin.readline())
	for _ in range(T):
		N,K = map(int,stdin.readline().split())
		arr = list(map(int,stdin.readline().split()))
		res = 1e9; resIdx = 0; curr = 0
		for i in range(K):
			curr ^= arr[i]				
		if res > curr: 
			res = curr; 
		for i in range(K,N):
			curr ^= arr[i - K];
			curr ^= arr[i];
			if (res > curr) and (i > resIdx):
				res = curr
				resIdx = i - K + 1					
		stdout.write(str(resIdx+1)+'\n')

main()