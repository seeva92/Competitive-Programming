from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
	t = int(stdin.readline())
	for _ in range(t):
		stk = []
		s = stdin.readline()
		cnt = 0
		for v,i in enumerate(s):
			print(i)
			if len(stk)==0 or i=='(':
				stk.append(i)
			elif stk[len(stk)-1]=='(' and i==')':				
				stk.pop()
				print(stk)
				cnt+=1

		stdout.write(str(cnt*2)+'\n')
main()