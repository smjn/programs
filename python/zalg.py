#! /usr/bin/env python

def effZ(st):
    z = [0]*len(st)
    (left,right)=(0,0)
    for k in xrange(1,len(st)):
        if k > right:
            left = right = k
            while right<len(st) and st[right]==st[right-left]:
                right += 1
            z[k] = right - left
            #get back at next position
            right -= 1
        else:
            t = right - k
            #inside box
            if z[t] < right-k+1:
                z[k] = z[t]
            else:
                left = k
                while right<len(st) and st[right] == st[right-left]:
                    right += 1
                z[k] = right-left
                right -= 1

    print z
    return z

def naiveZ(st):
    z = [0]
    for i in xrange(1, len(st)):
        (j,k) = (0,i)
        while k<len(st) and j<len(st) and st[j]==st[k]:
            j+=1
            k+=1
        z.append(j)
    
    print z
    return z

def patZ(text, patt, delim, which=0):
    st = patt+delim+text
    print "%s in %s found at:" % (patt, text)
    pos = []
    z = []
    z = which and effZ(st) or naiveZ(st)
    for i in xrange(len(z)):
        if len(patt) == z[i]:
            start = i - len(patt) - len(delim)            
            pos.append(start)
    print pos
    return pos


if __name__ == "__main__":
    #naiveZ("aabxaayaab")
    pos = patZ("xabcabzabc", "abc", "#")
    #effZ("aabxaayaab")
    pos = patZ("xabcabzabc", "abc", "#", 1)
