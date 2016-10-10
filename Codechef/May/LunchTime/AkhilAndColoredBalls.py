from sys import stdin,stdout
stdin = open("E:\\1.txt","r")
stdout = open("E:\\2.txt","w")
for a in range(int(stdin.readline().strip())):
	x = stdin.readline().strip()
	y = stdin.readline().strip()
	i=0; n = len(x)
	while i<n:
		if x[i] == y[i]:
			if x[i] == 'B':
				stdout.write('W')
			else:
				stdout.write('B')
		else:
			stdout.write('B')
		i+=1
	stdout.write('\n')