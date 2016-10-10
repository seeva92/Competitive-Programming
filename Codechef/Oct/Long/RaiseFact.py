from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def mul(a,b):
	temp = [[0,0],[0,0]]
	i = 0
	while i<2:
		j = 0
		while j<2:
			k = 0
			while k<2:
				temp[i][j]+= (a[i][k] * b[k][j])
				k+=1
			j+=1
		i+=1
	return temp

def exponen(a,b):
	res = [[1,0],[0,1]]
	while b>0:
		if b%2!=0: res = mul(res,a)
		a = mul(a,a); b//=2
	return res

def main():
	# global mat,I
	mat = [[1,1],[1,0]]
	res = exponen(mat,10000000)
	# print(res)
	print((res[0][0] * 1) + (res[0][1] * 0))
main()