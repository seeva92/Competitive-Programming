from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
a  = list(map(int,stdin.readline().strip().split()))
b = list(map(int,stdin.readline().strip().split()))
x =0; y=0;
for i in range(3):
	if a[i] < b[i]:
		y+=1
	elif a[i]>b[i]:
		x+=1
stdout.write(str(x)+" "+str(y))
