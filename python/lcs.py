#! /usr/bin/python

def lcs(s1,s2,m,n):
	if m==0 or n==0:
		return 0

	if s1[m-1] == s2[n-1]:
		return 1 + lcs(s1,s2,m-1,n-1)
	else:
		return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n))

print lcs("sushant","mahajan",7,7)
