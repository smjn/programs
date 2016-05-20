#!/usr/bin/env python

test=input()
for t in xrange(1,test+1):
	(n,k) = map(int, raw_input().split())
	ls=[]
	for r in xrange(4):
		ls.append(tuple(map(int,raw_input().split())))

	proc1={}
	proc2={}

	for i in xrange(len(ls[0])):
		for j in xrange(len(ls[1])):
			key=ls[0][i]^ls[1][j]
			if key in proc1:
				proc1[key]+=1
			else:
				proc1[key]=1

	for i in xrange(len(ls[2])):
		for j in xrange(len(ls[3])):
			key=ls[2][i]^ls[3][j]
			if key in proc2:
				proc2[key]+=1
			else:
				proc2[key]=1


	ans=0
	for key in proc1.keys():
		if k^key in proc2:
			ans+=proc1[key]*proc2[k^key]

	print "Case #%d: %d" % (t,ans)