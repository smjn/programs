#! /usr/bin/env python

import random
mod = 1000000009
def mul(m1,m2):
    m3=[0]*4
    m3[0] = (m1[0]*m2[0]+m1[1]*m2[2])%mod
    m3[1] = (m1[0]*m2[1]+m1[1]*m2[3])%mod
    m3[2] = (m1[2]*m2[0]+m1[3]*m2[2])%mod
    m3[3] = (m1[2]*m2[1]+m1[3]*m2[3])%mod

    return m3
    
def exp(m,n):
    if n==1:
        return m
    if n%2:
        return mul(m,exp(m,n-1))
    else:
        temp = exp(m,n/2)
        return mul(temp,temp)
		
t=input()
for _ in xrange(t):
    n=int(random.random()*mod)#input()
    if n<=2:
        print (10,99)[n==2]
    else:
        m=exp([10,-1,1,0], n-2)
        print (m[0]*99 + m[1]*10)%mod
