from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def gcd(a,b):
	if b==0: return a
	return gcd(b,a%b)

def main():
	n = int(stdin.readline())
	a = list(map(int,stdin.readline().split()))
	a.append(1)
	total = ((n-1)*(n))//2
	top = 0
	c = 0
	for i in a:
		if i == 0: c+=1
		else: 
			top += (((c-1)*c)//2)
			c = 0
	stdout.write(str(top//gcd(top,total))+" "+str(total//gcd(top,total))+'\n')

main()