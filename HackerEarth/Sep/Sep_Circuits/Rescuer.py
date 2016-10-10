import sys
from math import sqrt
sys.stdin = open("/Users/seeva92/Workspace/Contests/1.txt", "r")
sys.stdout = open("/Users/seeva92/Workspace/Contests/2.txt", "w")
t,X1,X2,Y1,Y2,v1,v2 = 0,0.0,0.0,0.0,0.0,0.0,0.0
eps = 1e-8
def findMin(low,high):
	res = 0.0;
	# print(X1,X2,Y1,Y2,V1,V2)
	while(low<=high):
		mid = low + ((high - low) / 2.0);
		midv = (sqrt((X1 - mid) * (X1 - mid) + ( -Y1) * ( -Y1)) / V1) + (sqrt((X2 - mid) * (X2 - mid) + ( -Y2) * ( -Y2)) / V2);
		midpv = (sqrt((X1 - (mid - eps)) * (X1 - (mid - eps)) + ( -Y1) * ( -Y1)) / V1) + (sqrt((X2 - (mid - eps)) * (X2 - (mid - eps)) + ( -Y2) * ( -Y2)) / V2);
		midnv = (sqrt((X1 - (mid + eps)) * (X1 - (mid + eps)) + ( -Y1) * ( -Y1)) / V1) + (sqrt((X2 - (mid + eps)) * (X2 - (mid + eps)) + ( -Y2) * (-Y2)) / V2);
		if(midpv >= midv and midv<= midnv):
			return midv;
		if(midpv >= midv and midv >= midnv):
			low = mid+eps
			res = midnv
		else:
			res = midpv
			high = mid-eps
	return res

t = int(input())
for ti in range(t):
	X1,Y1,X2,Y2,V1,V2 = map(float,input().split());
	if(X1 == X2):
		print("{0:.5f}".format(sqrt((X1-X1)*(X1-X1) + (-Y1)*(-Y1))/V1 + sqrt((X2-X2)*(X2-X2) + (-Y2)*(-Y2))/V2))
	elif X1>X2:
		X1,X2,Y1,Y2,V1,V2 = X2,X1,Y2,Y1,V2,V1		
		print("{0:.5f}".format(findMin(X1,X2)))
	else:
		print("{0:.5f}".format(findMin(X1,X2)))


# 208.88170644163475
# 140644.7312710823
# 26185.941929229353
# 210.2744743452438
# 139.26176693442022
# 2.3570226039551585

# 208.71999
# 140613.71400
# 26185.93485
# 37.18089
# 139.11210
# 2.31265


