import sys
sys.stdin = open("/Users/seeva92/Workspace/Contests/1.txt", "r")
sys.stdout = open("/Users/seeva92/Workspace/Contests/2.txt", "w")
n = int(input())
string = input()
def compute():
	res = 0
	
		for i in range(0,26):
			for j in range(0,26):
				flag = True
				curr = 0
				pIdx = -1
				while(True):
					if flag:					
						pIdx = s.find(chr(ord('a')+i),pIdx+1)
						if pIdx == -1:
							break
						else:
							curr+=1
							flag = False
					else:
						pIdx = s.find(chr(ord('a')+j),pIdx+1)
						if pIdx == -1:
							break
						else:
							curr+=1
							flag = False					
				res = max(res,curr)			
				curr = 0
				flag = True			
				for k in s:
					if flag:
						if chr(ord('a')+j) != k:
							continue
						else:
							curr+=1
							flag = False
					else:
						if chr(ord('a')+i) != k:
							continue
						else:
							curr+=1
							flag = True

				res = max(res,curr)			
				# print(res)
	print(res)		


compute()

