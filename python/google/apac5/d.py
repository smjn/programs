#!/usr/bin/env python

test = input()


def update(p, v, n, dp):
	while p<=n:
		dp[p] += v
		p += p&(-p)

def query(b,dp): 	
  s = 0
  while b>0:
  	s+=dp[b]
  	b -= b&(-b)
  return s

for t in xrange(1,test+1):
	(n,q) = map(int, raw_input().split())
	arr = map(int, raw_input().split())

	arr2 = []
	for s in xrange(len(arr)):
		x = 0
		for e in xrange(s,len(arr)):
			x += arr[e]
			arr2.append(x)	

	arr2 = sorted(arr2)

	dp = [0]*(len(arr2)+1)
	for i in xrange(len(arr2)):
		update(i+1, arr2[i], len(arr2), dp)

	print "Case #%d:" % t
	for i in xrange(q):
		(l,r) = map(int, raw_input().split())
		print query(r, dp)-query(l-1, dp)