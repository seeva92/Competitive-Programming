import sys
from random import randint
sys.stdout = open("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt","w")
for j in range(100):
	for i in range(5):
		print(randint(-15,15),end=' ')
	print('-999999')	
