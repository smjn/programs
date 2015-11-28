#! /usr/bin/env python

(text, prefix, suffix) = ("nothing", "bruno", "ingenious")
#(text, prefix, suffix) = ("ab", "b", "a")

subs = []
for i in xrange(len(text)):
	for j in xrange(i, len(text)):
		subs.append(text[i:j+1])

prefs = []
for i in xrange(len(prefix)-1,-1,-1):
	prefs.append(prefix[i:len(prefix)])

sufs = []
for i in xrange(len(suffix)):
	sufs.append(suffix[0:i+1])

tot = 0
gstmax = []
for st in subs:
	gmax1 = 0
	cstmax = ""
	for i in xrange(len(st)):
		if st[0:i+1] in prefs:
			if gmax1<=i+1:
				gmax1 = i+1
				#cstmax = st

	gmax2=0
	for i in xrange(len(st)-1,-1,-1):
		if st[i:len(st)] in sufs:
			gmax2 = max(gmax2, len(st)-i)

	if tot<=gmax1+gmax2:
		tot = gmax1+gmax2
		#if cstmax:
			#gstmax.append((tot,cstmax))
		#print tot,st
		gstmax.append((tot,st))

cand = []
for i in gstmax:
	if i[0]==tot:
		cand.append(i[1])

print sorted(cand)[0]


