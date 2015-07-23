/*
 *
 * Output:
 *Function main:35 lines
Function g:8 lines
Function f:5 lines
Function h:2 lines
 */

#include <stdio.h>
void g();
void f();
void h();
int main() {
  long a, b, x, y, t, gcd, lcm;

  a = x;
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
  lcm = (x*y)/(a-b);
  t = a+b+x+y+t;

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

