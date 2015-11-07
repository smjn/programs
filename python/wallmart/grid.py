#! /usr/bin/env python

(n,m) = map(int,raw_input().split())

grid=[]
graph={}
ele={}
visited=set()
comp=0
compl={}

sent=1;

def explore2(i,j,n,m):
	if i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1:
		return	
	grid[i][j]=sent
	explore2(i-1, j,n,m)
	explore2(i+1, j,n,m)
	explore2(i, j-1,n,m)
	explore2(i, j+1,n,m)


def explore(k):
	global comp,graph,visited,compl
	visited.add(k)
	for i in graph[k]:
		if i not in visited:
			compl[comp]+=1
			explore(i)

def dfs():
	global comp,graph,visited,compl
	for k in graph.keys():
		if k not in visited:
			comp+=1
			compl[comp]=1
			explore(k)

def makeGraph():
	global grid,ele
	for i in range(0,len(grid)):
		for j in range(0,len(grid[0])):
			if grid[i][j]!=0:
				if not graph.has_key(ele[(i,j)]):
					adj=[]
					for x in [(i,j-1),(i,j+1),(i-1,j),(i+1,j)]:
						if ele.has_key(x):
							adj.append(ele[x])

					graph[ele[(i,j)]] = adj

for i in range(n):
	ls=map(int,raw_input().split())
	grid.append(ls)

num=0
for i in range(0,len(grid)):
	for j in range(0,len(grid[0])):
		if grid[i][j]==1:
			ele[(i,j)]=num
			num+=1

for i in range(0,n):
	for j in range(0,m):
		if grid[i][j]==1:
			sent+=1
			explore2(i, j, n, m)

count={}
for i in range(0,n):
	for j in range(0,m):
		if grid[i][j]>1:
			if count.has_key(grid[i][j]):
				count[grid[i][j]]+=1
			else:
				count[grid[i][j]]=1

print sent-1,count.values()				




# makeGraph()
# dfs()
# print comp,
# for k in compl.keys():
# 	print compl[k],



