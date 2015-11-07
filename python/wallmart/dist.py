#! /usr/bin/env python
(n,m) = map(int, raw_input().split())
(fx,fy) = map(int, raw_input().split())
(sx,sy) = map(int, raw_input().split())

(dx,dy,dd) = (abs(fx-sx), abs(fy-sy), 0)

if dx==1 and dy==1 or dx==0 and dy==1 or dx==1 and dy==0:
	print 2
	exit()

if dx==dy:
	print (dx+dy)/2
	exit()

print max(dx,dy)


