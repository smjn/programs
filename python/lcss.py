#! /usr/bin/python
import sys
import pprint
(s1,s2)=(sys.argv[1],sys.argv[2])

print s1,s2
m=len(s1)
n=len(s2)
ls = [[0 for i in range(n+1)] for _ in range(m+1)]
print ls
for i in range(0,m):
	for j in range(0,n):
		if s1[i] is s2[j]:
			ls[i+1][j+1] = ls[i][j] + 1
		else:
			ls[i+1][j+1] = 0

print max(max(ls,key=lambda x:max(x)))

