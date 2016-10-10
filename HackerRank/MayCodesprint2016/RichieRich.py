from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
def main():
	n,k = map(int,stdin.readline().strip().split())
	num = list(stdin.readline().strip())
	i,j = 0,len(num)-1
	if k>=n:
		stdout.write("9"*n)
		return;

	unm = set()
	while i<=j:
		if num[i]!=num[j]:
			num[i],num[j] = max(num[i],num[j]),max(num[i],num[j])
			unm.add(i)
		i, j = i+1,j-1

	if len(unm)>k :stdout.write(str(-1)); return;

	k -= len(unm)
	i = 0; j= len(num)-1
	while i<=j and k>0:
		if num[i] != '9':
			if i in unm:
				num[i]= '9';
				# if i!=j:
				num[j] = '9'; k-=1;
			elif k>1:
				num[i] = '9'; k-=1
				if i!=j:
					num[j] = '9'; k-=1;
			elif k==1 and i==j:
				num[i] = '9'; k-=1
		i,j = i+1,j-1
	stdout.write("".join(num))
main()