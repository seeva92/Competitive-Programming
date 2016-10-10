# import sys
# sys.stdin = open("309_Div2_ProbC.txt")
n = (int(input()))

binomial = [[0 for x in range(1002)] for x in range(1002)]
binomial[0][0] = 1
i = 1
row = len(binomial)
col = len(binomial[0])
while i< row:
	binomial[i][0] = 1
	i+=1

mod = int(1e9+7)	
i =1
while i< row:
	j=1
	while j<col:
		binomial[i][j] = (binomial[i-1][j-1]+binomial[i-1][j])%mod
		j+=1
	i+=1

result = 1
total = 0
for i in range(n):
	x = (int(input()))
	result = (result * (binomial[total+x-1][x-1]))%mod
	total+=x
print(result)
