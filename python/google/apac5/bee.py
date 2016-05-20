#! /usr/bin/env python3

T = int(input())

for t in range(1,T+1):
    chars = input()
    sets = [set(x) for x in chars]
    num = 1
    for i in range(len(chars) - 1):
        sets[i].add(chars[i+1])
        sets[i+1].add(chars[i])
    for s in sets:
        num *= len(s)
    print ("Case #{:d}: {:d}".format(t, num))
