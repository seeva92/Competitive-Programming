from sys import stdin,stdout
# stdin = open("/home/shiva/Learning/1.txt","r")
# stdout = open("/home/shiva/Learning/2.txt","w")
def main():
	t = int(stdin.readline().strip())
	total = sum((i for i in map(int,stdin.readline().strip().split())))
	stdout.write(str(max(t,int((total+1)/2))))
main()