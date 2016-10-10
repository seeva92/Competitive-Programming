from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
def main():
	t = int(stdin.readline().strip())
	for ti in range(t):
		n,k = map(int,stdin.readline().strip().split())
		if k == 0:
			stdout.write(" ".join([str(i) for i in range(1,n+1)]))
		elif n%2==1:
			stdout.write("-1")
		else:
			arr = [0] * (n+1)
			flag = True
			for i in range(1,n+1):
				if i-k>0 and arr[i-k]==0:
					arr[i-k] = i
				elif i+k<=n and arr[i+k] == 0:
					arr[i+k] = i
				else:
					stdout.write("-1")
					flag = False
					break
			if flag:
				stdout.write(" ".join([str(arr[i]) for i in range(1,n+1)]))
		stdout.write('\n')
main()