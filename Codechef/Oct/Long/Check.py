from sys import stdin,stdout
stdin = open("/Users/seeva92/Workspace/Contests/1.txt","r")
stdout = open("/Users/seeva92/Workspace/Contests/2.txt","w")
def main():	
	x = int("1000110111011101100",2)
	while x > 0:
		stdout.write(str(x)+'\n')
		x= (x & x+1) - 1
	stdout.write("\n")
	arr = ["1000110111011101100",
"1000110111011101000",
"1000110111011100000",
"1000110111011000000",
"1000110111010000000",
"1000110111000000000",
"1000110110000000000",
"1000110100000000000",
"1000110000000000000",
"1000100000000000000",
"1000000000000000000",
"0000000000000000000"]
	for i in arr:
		stdout.write(str(int(i,2))+'\n')

main()