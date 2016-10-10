from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
def main():
	while True:
		arr = [0] * 20007
		f = list(map(int,stdin.readline().strip().split()))[1:]
		if len(f) == 0: break
		s = list(map(int,stdin.readline().strip().split()))[1:]
		for i in f: arr[i+10000]+=1
		for i in s: arr[i+10000]+=1
		inter = []
		c = 0
		for i in arr:
			if i==2: inter.append(c-10000)
			c+=1

		j =0; k= 0; jj = len(f); kk = len(s)
		best = 0
		for i in inter:
			fcurr = 0; scurr = 0
			while j<jj and f[j]!=i:
				fcurr+= f[j]
				j+=1
			while k<kk and s[k]!=i:
				scurr += s[k]
				k+=1
			best = best+fcurr if best+fcurr >= best+scurr else best+scurr

		fcurr = 0; scurr = 0
		while j<jj:
			fcurr+= f[j]
			j+=1
		while k<kk:
			scurr += s[k]
			k+=1
		best = best+fcurr if best+fcurr >= best+scurr else best+scurr
		stdout.write(str(best)+'\n')
main()