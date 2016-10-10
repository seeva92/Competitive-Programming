from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
    t = int(stdin.readline().strip())
    for i in range(t):
        x = int(stdin.readline().strip())
        if 1<= x%10 and x%10<= 5:
            stdout.write(str(x*2-2)+'\n')
        else:
            stdout.write(str(x*2-1)+'\n')
main()
