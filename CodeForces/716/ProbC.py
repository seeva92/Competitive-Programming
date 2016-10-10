n = int(input())
num = 2
def gcd(a,b):
	if b==0: return a
	return gcd(b,a%b)

def lcm(a,b):
	return (a*b)//gcd(a,b)

for i in range(1,n+1):
	y = lcm(i+1,i)
	x = y * y
	print(int((x-num)/i))
	num = y