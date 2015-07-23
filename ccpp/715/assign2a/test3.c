/*
 * Output
 *  Function main:40 lines
Function g:5 lines
 *
 */

#include <stdio.h>

int g(int x);
int main ()
{
	int a,b,c,d,h,i,j;
	scanf("%d",&h);
	while(h--)
	{
		if(h!=0)
		{
			while(a<50)
			{
				if(b<c)
					d=100;
				else
					d=50;
				g(g(g(d)));
			}
		}
		else
		{
			for(i=0;i<d;i++)
			{
				j=j+i;
			}
		}
	}
	return 0;
}

int g(int x){
	return x+sizeof(x);
}
