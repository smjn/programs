#include <stdio.h>
int add1(int,int);
int add_2(int,int);
int add2(int,int);
int add(int);
//int add2(int,int);
int main ()
{
	int i,j,a=12,b=22,c,d;

/*	for(i=1;i<100;i++)
		d=a+b;
	//c=a+b;

	while(j<100)
	{c=a+b;j++;}
*/
	c=a+b;

	d=add(a);

	d=add1(a,b);
	d=add_2(a,b);
	d=add1(a,b);
	c=a+b;
	//c=add_2(a,b);
	//c=add1(a,b);
	//int c1=add_2(a,b);
	//int c2=add2(a,b);

	return 0;
}



int add_2(int m,int n)
{
	int c1=m+n;
	c1=m+n;

	 int c2=m+n;
	// c2= add1(m,n);
	 return c1;

	}

int add1(int m,int n)
{
	//int c1=add_2(m,n);
	//int c2=add2(m,n);
	// c2=add_2(m,n);
	int c4=m+n;
	return c4;

}


int add2(int m,int n)
{
	int c1=m+n;
	int c2= add1(m,n);
	c2= add_2(m,n);
	return c1;

	}


int add(int m)
{
	int n=7;
	int c1=m+n;
	c1=m+n;

	 int c2=m+n;
	// c2= add1(m,n);
	 return c1;

	}
