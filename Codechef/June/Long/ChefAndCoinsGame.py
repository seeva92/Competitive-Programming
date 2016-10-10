from sys import stdin,stdout
# stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
# stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():
    # stdout.write("wow")
    t = int(stdin.readline().strip())
    for i in range(t):
        x = int(stdin.readline().strip())
        if x%6 == 0:
            stdout.write("Misha\n")
        else:
            stdout.write("Chef\n")
main()
