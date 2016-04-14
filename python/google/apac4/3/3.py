#! /usr/bin/env python
# i have used python-netaddr library to implement the solution
import netaddr as na

test=input()

for t in xrange(test):
	print "Case #%d:" % (t+1)
	n=input()

	ls=[]
	for _ in xrange(n):
		ls.append(na.IPNetwork(raw_input()))

	for addr in na.cidr_merge(ls):
		print addr.cidr
