#! /usr/bin/env python

def findMax(v, cord, q, i, cmin):
	if q<0:
		return 10e18
	if q==0:
		return cmin
	if i==len(v):
		return cmin
	if cord[0]==0:
		return cmin

	return min(findMax(v, cord, q-abs(cord[1]-v[i]), i+1, v[i]*(0-cord[0])),
				findMax(v, cord, q, i+1, cmin))

test = input()

for t in xrange(test):
	[n,m,q] = map(int, raw_input().split())
	v=[]
	v=map(int, raw_input().split())
	cord=[]
	for _ in xrange(n):
		cord.append(map(int,raw_input().split()))

	for c in cord:
		print findMax(v, c, q, 0, 0)

	

