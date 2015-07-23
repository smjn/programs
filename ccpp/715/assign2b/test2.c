/*
 *
 * Output
Function main:Recursion
Function f:3 lines
Function g:Recursions
 *
 */

#include <stdio.h>
int f(int x);
int g(int* f);
int main ()
{
	int a,b,c,d,h;
	scanf("%d",&h);
	printf("%d",h);
	if(h!=0)
	{
		while(a<50)
		{
			if(b<c)
				d=100;
			else
				d=50;
		}
		f(d);
		f(g(&d));
	}

	else
	{
		while(a<50)
		{
			if(b>=c)
				d=200;
			else
				d=150;
		}
	}

	return 0;
}

int f(int x){
	return 0;
}
int g(int* f1){
	f(2);
	//main();
	return *f1;
}

