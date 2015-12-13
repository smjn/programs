#! /usr/bin/env python

patt = "".join(map(lambda x:str(x),[2,2,3,3,3,4,4,4,4]))

x=set()
def func(x):
    return int(x)>3000

def mycount(soFar, rest, k, pred=lambda x:True):
    if k==0 and pred(soFar)==True:
        x.add(soFar)
        return

    for i in xrange(len(rest)):
        mycount(soFar+rest[i],rest[0:i]+rest[i+1:],k-1,pred)

mycount("",patt,4)
print len(x)

x=set()
mycount("",patt,4,func)
print len(x)




