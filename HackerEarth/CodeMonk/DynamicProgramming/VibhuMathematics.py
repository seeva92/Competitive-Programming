from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	arr = [0 for i in range(1000007)]
	arr[0] = 1; arr[1] = 1
	for i in range(2,1000007):
		arr[i] = arr[i-1] + ((i-1) * arr[i-2])
		arr[i] %= (1000000007)

	t = int(stdin.readline())
	for i in range(t):
		n = int(stdin.readline())
		stdout.write(str(arr[n])+'\n')

main()