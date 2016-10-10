import sys

# sys.stdin = open("/Users/seeva92/Workspace/Contests/1.txt", "r");
# sys.stdout = open("/Users/seeva92/Workspace/Contests/2.txt", "w");
n = int(input())
s = input()
res = '';
for i in range(0,n):
    for j in range(i+1,n+1):
    	if res<s[i:j]:
    		res = s[i:j]    


sys.stdout.write(res+'\n')
