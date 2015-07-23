/*
 *
 * Output:
Function x:4 lines
Function y:7 lines
Function z:Recursion
Function main:50 lines
Function g:8 lines
Function f:5 lines
Function h:2 lines
 */

#include <stdio.h>
#include "test4.c"
void g();
void f();
void h();
int main() {
  long a, b, t, gcd, lcm;

  a = 10;
  b = -1300900;

 a++;
  while (b != 0) {
    t = b;
    g();
    f();
    b = a /  b;
    a = t;
  }
  f();
  f();
  gcd = a;
  lcm = (100)/(a-b);
  t = a+b+t;
  x();
  y();
  return 0;
}

void g(){
	f();
	h();
}

void f(){
	int a,b,c;
	a=10;
	b=10;
	c=10;
	a=c;
}
void h(){
}

