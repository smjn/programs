#! /usr/bin/env python

test = input()
day = 24*60*60

def gcd(a,b):
	if b==0:
		return a
	return gcd(b, a%b)

def getSecs(t):
	return (t[0]*60+t[1])*60+t[2]

for t in xrange(test):
	print "Case #%d: " % (t+1),
	[g,w,h,b,x] = [map(int,raw_input().split(":")) for _ in xrange(5)]
	d=input()

	poll = getSecs(x)
	tot = d*day

	(ds,dw) = (day-getSecs(b)+getSecs(g),getSecs(h)-getSecs(w))

	#print ds,dw,poll
	if ds >= poll or dw >= poll:
		print -1
		continue

	ans=0

	(bs,ws) = (getSecs(b),getSecs(w))
	for i in xrange(d):
		#gcd(a, b)
		if ((i+1)*poll - bs)%day == 0 or ((i+1)*poll - ws)%day==0:
			ans+=1
			break

	print tot/poll + ans
