from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
def main():
	a = list(map(int,stdin.readline().strip().split()))
	a.sort()
	total = sum(1 for w in range(1,a[0]+1) for x in range(w,a[1]+1) for y in range(x,a[2]+1) for z in range(y,a[3]+1) if w^x^y^z !=0)
			# if w == x:
			# 	aa = a[3]-x
			# else:
			# 	aa = a[3] - x + 1
			# n = a[2] - x + 1
			# total+= (n*(aa+(aa+(n-1)*-1)))//2


	# sum((n*(a[3]-x + (a[3]-x + (afor w in range(1,a[0]+1) for x in range(w,a[1]+1)
		
	stdout.write(str(total))
main()