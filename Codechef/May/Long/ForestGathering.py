# import sys
# sys.stdin = open("/home/shiva/Learning/1.txt","r")
# sys.stdout = open("/home/shiva/Learning/2.txt","w")
N,W,L = map(int,input().strip().split())
tree =  [tuple(map(int,input().strip().split())) for i in range(N)]

def possible(time):
	required = W
	for h,s in tree:
		got = h+(s*time)
		if got>=L:
			required-= got
			if(required<=0): return True

	return False

lo = -1
hi = 10**18+5
while hi-lo>1:
	mid = lo+hi >> 1
	if possible(mid):
		hi = mid
	else:
		lo = mid

print(hi)