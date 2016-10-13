from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():	
	t = int(stdin.readline())
	for _ in range(t):
		l1,l2,l3,N = stdin.readline().split()
		temp = int(l1+(l2*int(N))+l3,2)
		c = 1
		while temp>0:
			temp = (temp & temp+1)-1
			c+=1
		stdout.write(str(c-1)+'\n')
main()







