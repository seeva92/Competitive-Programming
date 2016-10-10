import bisect
def countSmaller(nums):
    sortedArray = []
    res = []
    for i in range(len(nums) - 1, -1, -1):
        res.append(bisect.bisect_right(sortedArray, nums[i]))
        bisect.insort(sortedArray, nums[i])
    return res[::-1]
import sys
sys.stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
sys.stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
n,k = map(int,input().split())
arr = list(map(int,input().split()))
print(n,k)
print((arr))
temp = countSmaller(arr)
for i in temp:
	print(i,end=' ')