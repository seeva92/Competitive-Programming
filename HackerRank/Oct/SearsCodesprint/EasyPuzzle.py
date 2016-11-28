from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def gcd(a,b):
	if b==0: return a
	return gcd(b,a%b)
def main():
	t = int(stdin.readline())
	for _ in range(t):
		n, k = map(int,stdin.readline().split())
		res = 0
		for i,val in enumerate(map(int,stdin.readline().split())):
			if i == 0: res = val				
			else: res = (res *val)//gcd(res,val)

		if res%k == 0: stdout.write("YES\n")			
		else: stdout.write("NO\n") 
			
main()