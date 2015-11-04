#! /usr/bin/env python
import operator as op

t=input()

for z in xrange(t):
	p=input()
	s=map(int,raw_input().split())
	n=input()

	comp=[]
	for n1 in xrange(n):
		#weight, p names
		comp.append(raw_input().split())
		comp[n1][0]=int(comp[n1][0])
	m=input()

	aths={}
	for j in xrange(n):
		for (i,name) in enumerate(comp[j][1:],1):
			score=0 if i>p else s[i-1]*comp[j][0]
			if name in aths:				
				aths[name].append(score)
			else:
				aths[name]=[score]

	#print aths

	for k in aths.keys():
		l = len(aths[k])
		(val,i)=(0,0)
		for score in sorted(aths[k],reverse=True):
			i+=1
			val+=score
			if i == min(l,m):
				aths[k]=val
				break
	#print aths

	ls={}
	for k in sorted(aths,key=aths.get,reverse=True):
		if aths[k] in ls:
			ls[aths[k]].append(k)
		else:
			ls[aths[k]]=[k]

	i=1
	print "Case #%d:" % (z+1)
	for k in sorted(ls,reverse=True):
		j=0
		for x in sorted(ls[k]):
			j+=1
			print "%d:" % i,x
		i+=j

	



