from sys import stdin,stdout
# stdin = open("/home/shiva/Learning/1.txt","r")
# stdout = open("/home/shiva/Learning/2.txt","w")
class SegTree:
	"""docstring for SegTree"""


	def __init__(self, arr):
		super(SegTree, self).__init__()
		self.arr = arr
		self.seg = [0] * (3*(len(arr)+1))
		self.build(0,len(self.arr)-1,1)

	"""a[0] = left, a[1]= right, a[2]=sum, a[3]= best"""
	def calculate(self,a,b):
		l = a[2]+b[0] if a[2]+b[0] > a[0] else a[0]
		r = b[2] + a[1] if b[2] + a[1] > b[1] else b[1]
		s = a[2] + b[2]
		b = max(a[1]+b[0],max(a[3],b[3]))
		return (l,r,s,b)

	def build(self,i,j,idx):
		if(i==j):
			self.seg[idx] = tuple([self.arr[i]] * 4); return;
		self.build(i,(i+j)//2,idx<<1)
		self.build((i+j)//2 + 1, j,(idx<<1)+1)
		self.seg[idx] = self.calculate(self.seg[idx<<1] , self.seg[(idx<<1)+1])

	

	def query(self,i,j,l,r,idx):
		if i>j or r<i or l>j: return tuple([-99999999999]*4)
		if l<=i and j<=r: return self.seg[idx]

		return self.calculate(self.query(i,(i+j)//2,l,r,idx<<1), self.query((i+j)//2+1,j,l,r,(idx<<1)+1))

	def update(self,i,j,l,r,idx):	
		if i>j or l<i or l>j: return
		if i==j:
			self.arr[l] = r;
			self.seg[idx] = tuple([r]*4); return
		if l<=((i+j)//2):
			self.update(i,(i+j)//2,l,r,idx<<1)	
		else:
			self.update((i+j)//2 + 1,j,l,r,(idx<<1)+1)
		self.seg[idx]= self.calculate(self.seg[idx<<1] ,self.seg[(idx<<1)+1])


def main():
	n = stdin.readline()
	arr = list(map(int,stdin.readline().strip().split()))
	m = int(stdin.readline().strip())
	s = SegTree(arr)
	for a in range(m):
		t,x,y = map(int,stdin.readline().strip().split())
		if t == 0:
			s.update(0,len(arr)-1,x-1,y,1)
		else:
			stdout.write(str(s.query(0,len(arr)-1,x-1,y-1,1)[3])+'\n')	
main()