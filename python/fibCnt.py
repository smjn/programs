#! /usr/bin/env python

import random
#mod = 1000000009
def mul(m1,m2):
    m3=[0]*4
    m3[0] = (m1[0]*m2[0]+m1[1]*m2[2])
    m3[1] = (m1[0]*m2[1]+m1[1]*m2[3])
    m3[2] = (m1[2]*m2[0]+m1[3]*m2[2])
    m3[3] = (m1[2]*m2[1]+m1[3]*m2[3])

    return m3
    
def exp(m,n):
    if n==1:
        return m
    if n%2:
        return mul(m,exp(m,n-1))
    else:
        temp = exp(m,n/2)
        return mul(temp,temp)
		
n=input()
if n==1:
    print 1,0
if n==2:
    print 0,1
m=exp([1, 1, 1, 0],n-1)
print m[0],m[1]
