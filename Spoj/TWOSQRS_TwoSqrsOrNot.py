from sys import stdin,stdout
# stdin = open("/home/shiva/Learning/1.txt","r")
# stdout = open("/home/shiva/Learning/2.txt","w")
primelist = [2]
append = primelist.append
def mysieve(n):
	primes = [True] * (n);
	sqrtn = (int(n**.5)+1) | 1
	for i in range(3,sqrtn,2):
		if primes[i]:
			append(i)
			primes[i*i::2*i] = [False] * ((n-(i*i)-1)//(2*i)+1)

	for i in range(sqrtn,n,2):
		if primes[i]:
			append(i)

	return primelist

def isSumTwoSquare(n):
	for i in primelist:
		cnt = 0
		while n%i==0:
			n/=i
			cnt+=1
		if i%4==3 and cnt%2==1:
			return False
	if n%4==3:
		return False
	return True

mysieve(10**6+1)
# stdout.write(str(primelist))
t = int(stdin.readline())
for i in range(t):
	flag = False;
	n = int(stdin.readline())
	if(int(n**.5) == n): 
		stdout.write("Yes\n")
	else:
		if isSumTwoSquare(n):
			stdout.write("Yes\n")
		else:
			stdout.write("No\n")
