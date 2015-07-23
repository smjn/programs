

#include <stdio.h>
 
int main() {
  int a, b, x, y, t, gcd, lcm;
  
  a = x;
  b = 1;
  t=-a;
 
 a++;	
  while (b != 0) {
    t = b;
    b = a /  b;
    a = t;
  }
 
  gcd = a;
  lcm = (x*y)/(a-b);
  t = a+b+x+y+t;
 
  return 0;
}
