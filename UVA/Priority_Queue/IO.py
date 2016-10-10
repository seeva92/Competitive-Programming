import sys
from random import randint
sys.stdout = open("1.txt","w")
for j in range(1000):
	for i in range(10):
		print(randint(-15,15),end=' ')
	print('-999999')	
