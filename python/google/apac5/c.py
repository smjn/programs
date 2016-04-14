#!/usr/bin/env python
import sys
sys.setrecursionlimit(2**30)
ans=0.0
k=0

def dfs(n, x, prob):
	global ans,k
	if n == 0:
		ans += x*prob
		return
	dfs(n - 1, x & k, prob*a)
	dfs(n - 1, x | k, prob*b)
	dfs(n - 1, x ^ k, prob*c)

test = input()
for t in xrange(1,test+1):
	inp = raw_input().split()
	(n,x,k) = map(int,inp[:3])
	(a,b,c) = map(float,inp[3:])
	a /= 100
	b /= 100	
	c /= 100	
	ans = 0.0
	dfs(n, x, 1)
	print "Case #%d: %.9f" % (t,ans)
