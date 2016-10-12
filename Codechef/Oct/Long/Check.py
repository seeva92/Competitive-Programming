from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():	
	x = int("010101101101101000",2)
	while x > 0:
		stdout.write(str(x)+" "+str(bin(x))[2:]+" "+'\n')
		x= (x & (x+1)) - 1
	stdout.write("\n")
	arr = ["010101101101101000",
"010101101101100111",
"010101101101011111",
"010101101100111111",
"010101101011111111",
"010101100111111111",
"010101011111111111",
"010100111111111111",
"010011111111111111",
"001111111111111111"]
	for i in arr:
		stdout.write(str(int(i,2))+'\n')

main()







