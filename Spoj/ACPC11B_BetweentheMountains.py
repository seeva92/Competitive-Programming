from sys import stdin,stdout
# stdin = open("/home/shiva/Learning/1.txt","r")
# stdout = open("/home/shiva/Learning/2.txt","w")
def closematch(f,val):
	l = 0; h = len(f)-1;
	best = 999999999
	while(l<=h):
		m = int((l+h)/2)
		if abs(f[m]-val) <= best:
			best = abs(f[m]-val)
		if f[m]<=val:
			l = m+1
		else:
			h = m-1
	return best

def main():
	for a in range(int(stdin.readline().strip())):
		f = list(map(int,stdin.readline().strip().split()))[1:]
		f.sort()
		# stdout.write(str(f)+'\n')
		s = list(map(int,stdin.readline().strip().split()))[1:]
		# stdout.write(str(s)+'\n')
		stdout.write(str(min(closematch(f,i) for i in s))+'\n')
main()