from sys import stdin,stdout
# stdin = open("E:\\1.txt","r")
# stdout = open("E:\\2.txt","w")
arr = [int(stdin.readline().strip()) for i in range(int(stdin.readline()))]
total = sum(1 if d!=0 and (a*b+c - d*e) ==d*f else 0
						for f in arr
							for e in arr
								for d in arr
									for c in arr
										for b in arr
											for a in arr)
stdout.write(str(total)+'\n')