from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	for t in range(int(stdin.readline())):
		X,Y,N,W,P1,P2 = map(int,stdin.readline().split())
		dp = [[float(0) for j in range(W+1)] for i in range(N+1)]
		P1 = .01 * P1; P2 = .01 * P2
		#Initial states
		for i in range(N+1):
			dp[i][0] = 1.0
		for i in range(1,N+1):
			for j in range(1,W+1):
				dp[i][j] = max((P1*dp[i-1][max(j-X,0)]) + (1.0-P1) * dp[i-1][max(j,0)],
								(P2 * dp[i-1][max(j-Y,0)]) + (1.0 - P2) * dp[i-1][max(j,0)])
		print(dp)
		stdout.write("{:.6f}".format(dp[N][W]*100)+'\n')
		

main()