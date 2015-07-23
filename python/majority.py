#! /usr/bin/python 
def major(ls):
	if len(ls) == 1:
		return ls[0]
	
	k = int(len(ls)/2)
	print ls,k
	print ls[0:k], ls[k:len(ls)]
	le = major(ls[0:k])
	re = major(ls[k:len(ls)])
	print "elem",le,re

	if le == re:
		return le

	(lcount,rcount) = (0,0)
	for i in ls:
		if i == le:
			lcount = lcount + 1

	for i in ls:
		if i == re:
			rcount = rcount + 1

	print "count",lcount,rcount

	if lcount >= k + 1:
		return le
	elif rcount >= k + 1:
		return re
	else:
		return -1

if __name__ == "__main__":
	print major([1,5,3,1,1])
