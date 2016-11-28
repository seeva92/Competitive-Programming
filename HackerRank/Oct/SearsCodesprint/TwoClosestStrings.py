from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():	
	t = int(stdin.readline())
	for _ in range(t):
		n,k = stdin.readline().split()
		n = list(n)		
		k = int(k)
		arr = [0 for i in range(len(n))]
		for i,v in enumerate(n):
			if k==0: break
			if v!='a':
				arr[i] = 1
				n[i] = 'a'
				k-=1
		arr.reverse()
		n.reverse()
		for i,v in enumerate(n):
			if k==0: break
			if v=='a' and arr[i]==0:
				n[i] = 'b'
				arr[i] = 1
				k-=1
		n.reverse()
		stdout.write((''.join(n))+'\n')
main()