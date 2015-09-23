#! /usr/bin/python

tot=[]

def solve(seen, rest, target):
    if rest=="":
        if eval(seen)==target:
            tot.append(seen)
    else:
        if seen=="":
            seen += rest[0]
            solve(seen, rest[1:], target)
        else:
            solve(seen+"+"+rest[0], rest[1:], target)
            solve(seen+"-"+rest[0], rest[1:], target)
            solve(seen+"*"+rest[0], rest[1:], target)

def addOps(num, target):
    solve("", num, target)
    for x in tot:
        print x
    return tot

if __name__ == "__main__":
    addOps("00", 0)


