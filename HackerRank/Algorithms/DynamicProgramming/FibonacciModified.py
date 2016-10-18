from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	t1,t2,n = map(int,stdin.readline().split())
	for _ in range(n-2):
		t1,t2 =t2,t1+(t2*t2)
	stdout.write(str(t2)+'\n')
main()