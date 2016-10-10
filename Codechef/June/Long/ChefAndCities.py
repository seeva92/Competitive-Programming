from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
from functools import reduce
from operator import mul
def main():
    # stdout.write("wow")
    N = int(stdin.readline().strip())
    arr = list(map(int,stdin.readline().strip().split()))
    Q = int(stdin.readline().strip())
    for i in range(Q):
        tmp = stdin.readline().strip().split()
        if len(tmp) == 3:
            t,p,q = map(int,tmp)
            arr[p-1] = q
        else:
            t,R = map(int,tmp)
            res = str(reduce(mul,(arr[i] for i in range(0,N,R)),1))
            stdout.write(res[0]+" "+str(int(res)%(1000000007))+'\n')
main()
