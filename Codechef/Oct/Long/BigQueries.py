from sys import stdin,stdout
from math import pow
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
class Node:	
	def __init__(self,mul,mulupd = 1,repupd = 0,i = 0,j=0):		
		self.mul = mul
		self.mulupd = mulupd
		self.repupd = repupd
		self.i = i
		self.j = j

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
	
def build(i,j,idx):		
	if i == j: 
		Sg[idx].mul = A[i].mul; Sg[idx].i = i; Sg[idx].j = j
		return		
	build(i,(i+j)//2,2*idx + 1); build((i+j)//2+1,j,2*idx + 2)
	Sg[idx].mul = Sg[2*idx+1].mul * Sg[2*idx+2].mul
	Sg[idx].i = i; Sg[idx].j = j
def upd(i,j,l,r,val,t,idx):
	if Sg[idx].mulupd != 1:
			Sg[2*idx+1].mulupd *= Sg[idx].mulupd
			Sg[2*idx+2].mulupd *= Sg[idx].mulupd			
			Sg[idx].mulupd = 1

	if (i>j) or (l>j) or (r<i): return
	if t == 1:
		Sg[idx].mul *= pow(val,Sg[idx].j-Sg[idx].i + 1)
		Sg[idx].mulupd = val
	else:
		pass

def query(i,j,l,r,idx):
	if (i>j) or (l>j) or (r<i): return Node(1)
	if l<=i and j<=r: return Sg[idx]
	return Node(query(i,(i+j)//2,l,r,2*idx+1).mul * query((i+j)//2+1,j,l,r,2*idx+2).mul)

def main():
	global N,M,A,Sg

	for _ in range(int(stdin.readline())):
		N,M = map(int,stdin.readline().split())
		A = list(Node(i) for i in map(int,stdin.readline().split()))
		Sg = list(Node(1) for i in range(4*len(A)+10))
		build(0,N-1,0)
		# for i in Sg: print(i.mul,i.mulupd,i.repupd,i.i,i.j)

		print(query(0,N-1,0,2,0).mul,
		query(0,N-1,3,4,0).mul,
		query(0,N-1,1,4,0).mul,
		query(0,N-1,0,4,0).mul)
main()