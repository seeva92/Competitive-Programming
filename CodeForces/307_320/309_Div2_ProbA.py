booklet = str(input())
i = 0
length = len(booklet)
alpha = 'abcdefghijklmnopqrstuvwxyz'
hashset = set()
while i<=length:
	for c in alpha:
		hashset.add(booklet[0:i]+c+booklet[i:])
	i+=1
print(len(hashset))