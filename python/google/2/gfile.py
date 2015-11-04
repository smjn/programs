#! /usr/bin/env python
import math

t=input()
big=10e18
for z in xrange(t):
	n=input()
	ls=[]
	for _ in xrange(n):
		ls.append(map(int,raw_input().split()))

	(isFound,mi1,mi2)=(big,-big,False)
	for c in ls:
		(p,k) = (c[0],c[1])
		if p==100:
			print "Case #%d:" % (z+1),k
			isFound=True
			break
		if p==0 and k==0:
			continue
		m1 = big if p==0 else 100*k/p
		m2=100*k/(p+1) + 1
		(mi1,mi2) = (min(mi1,m1),max(mi2,m2))

	if not isFound:
		if mi1==mi2:
			print "Case #%d:" % (z+1),int(mi1)
		else:
			print "Case #%d:" % (z+1),-1		