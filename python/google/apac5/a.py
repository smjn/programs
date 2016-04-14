#! /usr/bin/env python

test = input()
mod=10**9+7
for t in xrange(1,test+1):
    w = raw_input()
    ls=[]
    for c in w:
    	ls.append(set(c))
    ans = 1
    for i in xrange(len(w) - 1):
        ls[i].add(w[i+1])
        ls[i+1].add(w[i])
    for k in ls:
        ans = (ans*len(k))%mod
    print "Case #%d: %d" % (t,ans)



	




