import sys
# sys.stdin = open("309_Div2_ProbB.txt")
n = int(input())
map = dict()
max_value = -sys.maxsize-1
for i in range(n):
	arr = input()
	if arr in map:
		map[arr]+=1
	else:
		map[arr] = 1
	max_value = max(max_value,map[arr])
print(max_value)
	