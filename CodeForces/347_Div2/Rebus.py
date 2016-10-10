import sys
import psyco
sys.stdin = open("/home/shiva/Learning/1.txt", "r")
sys.stdout = open("/home/shiva/Learning/2.txt", "w")

def compute(plus,minus,total,inp):
	if plus == 1 and minus == 0:
		print(total); return
	elif (plus == 1 and minus == 1): 
		print("Impossible"); return
	elif (abs(plus-minus) > total):
		plus

	temp = total
	total += minus
	res = []
	if int(total/plus) > temp:
		print("Impossible"); return
	elif int(total%plus) == 0:
		res = [int(total/plus) for i in range(0,plus)]
	else:
		res = [int(total/(plus-1)) for i in range(0,plus-1)]
		res.append(total%(plus-1))
	
	j = 0
	prev = 0
	for i in inp.split():
		if j == 0:
			print(res[j],end=' ')
			j+=1
		elif i == '+' or i=='-':
			print(i,end=' ')
			prev = i
		elif i == '?':
			if prev == '+':

				print(res[j],end=' ')
				j+=1
			else:
				print('1',end=' ')
		else:
			print(i,end=' ')

inp = input()
plus =1
minus = 0
total = 0
for i in inp.split():
	if i=='?' or i=='=':
		continue
	elif i == '+':
		plus+=1
	elif i == '-':
		minus +=1
	else:
		total = int(i)

compute(plus,minus,total,inp)





