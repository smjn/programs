#include <stdio.h>

int *p, *q;
void callme (int);
void calle(int);
void callwe (int);
void callthe (int a);
int main ()
{
        int a, b, *c;
        p = &b;
        callme (a);
        return 0;
}

void callme (int a)
{
        int *d,i=0;
        a = *(p + 3);
        q = &a;
        d = q;
	callwe(a);
}

void calle(int a)
{
int b;
a=b;
return;
}


void callwe (int a)
{
        int *d,i=0;
        a = *(p + 3);
        q = &a;
        d = q;
	callthe(a);
}

void callthe (int a)
{
        int *d,i=0;
        a = *(p + 3);
        q = &a;
        d = q;
callme(a);
}

