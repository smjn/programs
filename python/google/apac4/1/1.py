#! /usr/bin/env python
import copy

def bfs(g,i,j,num):
	if i<0 or j<0 or i>=len(g) or j>=len(g[0]):
		return
	#print i,j
	if g[i][j]==1:
		g[i][j]=num
		bfs(g, i-1, j,num)
		bfs(g, i+1, j,num)
		bfs(g, i, j-1,num)
		bfs(g, i, j+1,num)

def doBfs(g):
	num=1
	no1=True
	for i in xrange(len(g)):
		for j in xrange(len(g[0])):
			if g[i][j]==1:
				no1=False
				num+=1
				bfs(g,i,j,num)

	#print g
	if no1:
		return 0
	return num-1


test=input()

for t in xrange(test):
	(r,c) = map(int, raw_input().split())
	g=[]
	for i in xrange(r):
		g.append(map(int,raw_input()))

	m=input()
	print "Case #%d:" % (t+1)
	for _ in xrange(m):
		ls=raw_input()
		if len(ls)==1:
			print doBfs(copy.deepcopy(g))
		else:
			(x,y,z)=map(int, ls[1:].split())
			#print x,y,z
			g[x][y]=z


