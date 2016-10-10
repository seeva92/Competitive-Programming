import sys
# sys.stdin = open("/home/shiva/Learning/1.txt", "r")
# sys.stdout = open("/home/shiva/Learning/2.txt", "w")
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

t = int(input())
for i in range(t):
	a, b = map(int,input().split())
	print(gcd(a,b))