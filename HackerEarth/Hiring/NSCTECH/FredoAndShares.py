from sys import stdin,stdout
from math import *
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def build(i,j,idx):
	if i == j: 
		sg[idx] = [arr[i]];
		return
	mid = (i+j)//2
	build(i,mid,2*idx+1); build(mid+1,j,2*idx+2)
	temp = sorted(set(sg[2*idx+1]+sg[2*idx+2]),reverse=True)
	sg[idx] = temp
	if len(temp) > 3:		
		sg[idx] = [sg[idx][0]] + [sg[idx][len(sg[idx])-2]] + [sg[idx][len(sg[idx])-1]]

def upd(i,j,idx,val,l):
	if i>j or l<i or l>j: return
	mid = (i+j)//2

	if l<= mid: 
		if i==j and i==l:
			sg[idx] = [val];
			return
		else: upd(i,mid,2*idx+1,val,l)
	else: upd(mid+1,j,2*idx+2,val,l)
	temp = sorted(set(sg[2*idx+1]+sg[2*idx+2]),reverse=True)	
	if len(temp) > 3:		
		sg[idx] = [temp[0]] + [temp[len(temp)-2]] + [temp[len(temp)-1]]
	else:
		sg[idx] = temp


def quer(i,j,idx,l,r):
	if i>j or r<i or l>j: return []
	if l<=i and j<=r: return sg[idx]
	lt = quer(i,(i+j)//2,2*idx+1,l,r)
	rt = quer((i+j)//2+1,j,2*idx+2,l,r)
	temp = sorted((lt+rt),reverse=True)	
	if len(temp) > 3:		
		return [temp[0]] + [temp[len(temp)-2]] + [temp[len(temp)-1]]
	return temp

def main():
	global n,m,arr,sg
	n,m = map(int,stdin.readline().split())
	arr = list(map(int,stdin.readline().split()))
	sg = list([0,0] for i in range(4*n+10))
	build(0,n-1,0)
	# print(sg)
	for _ in range(m):
		s = stdin.readline().split()
		if s[0] == 'q':
			tmp = quer(0,n-1,0,int(s[1])-1,int(s[2])-1)
			if len(tmp)<3: stdout.write("-1\n")			
			else: stdout.write(str(tmp[0]-tmp[1])+'\n')			
		else:
			upd(0,n-1,0,int(s[2]),int(s[1])-1)
main()