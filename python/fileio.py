def runIt():
    fp=open("/home/sushant/Desktop/test.hs","r")
    ls=[line for line in fp.readline()]
    ls=ls[0:len(ls)-1]
    print ls
if __name__=="__main__":
    runIt()
