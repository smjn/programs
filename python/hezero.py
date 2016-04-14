n=input()
a=map(int,raw_input().split())
q=input()

pd=str(reduce(lambda x,y:x*y, a))

for x in xrange(q):
	b=input()
	pd2=str(int(pd,b))
	print b,pd2
