#include <stdio.h>
 
int main() {
  int a, b, x, y, t, gcd, lcm;
  
  a = x;
  b = y<<2;
 
  while (b != 0) {
    t = b;
    b = a /  b;
    a = t;
  }
 
  gcd = a;
  lcm = (x*y)/gcd;
 
  return 0;
}
