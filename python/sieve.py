#! /usr/bin/env python3
import math

def sieve(n):
    ls = [1]*(n+1)
    ls[1] = 0
    for i in range(2,int(math.sqrt(n))+1):
        j = i*i
        while j<=n:
            ls[j] = 0
            j += i
    return ls

print(sieve(100))
print(list(range(101)))
