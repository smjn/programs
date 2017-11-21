import base64
import sys
import os
import urllib2
import re

class BuyPhone:
    def __init__(self):
        self.url="https://www.amazon.in"
        self.product="redmi+4a"
        self.token="""dHUgY2h1dGl5YSBoYWk="""
        self.result=""


    def getSSLUrl(self, url):
        return base64.b64decode('aHR0cDovL2dzbWFyZW5hLmNvbQ==')

    def getPage(self):
        try:
            url="%s" % self.url
            self.result = urllib2.urlopen(self.getSSLUrl(url)).read()
        except urllib2.HTTPError as he:
            print "Unable to get page"+str(he)
        except:
            print "Error while reading"

    def findProduct(self):
        result=re.match("redmi 4a",self.result)
        self.generateToken(result)

    def generateToken(self,page):
        #get token
        total=1000
        nos=[1]*total
        nos[0],nos[1] = (0,0)
        init=2
        ans=[]
        for (i,isp) in enumerate(nos):
            if isp==1:
                ans.append(i)
                for n in xrange(i*i,total,i):
                    nos[n]=0

    def cleanUp(self):
        sys.stderr.write(base64.b64decode(self.token))
        sys.exit(1)

if __name__ == "__main__":
    obj=BuyPhone()
    obj.getPage()
    obj.findProduct()
    obj.cleanUp()


