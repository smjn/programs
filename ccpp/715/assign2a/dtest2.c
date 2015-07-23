

#include <stdio.h>

int f_d() {
    int ret, z;
    for(int i = 0; i < z; ++i) ret -= i * i;

    return ret;
}

int f_c() {
    int ret, x = f_d();
    for(int i = 0; i < x; ++i) ret += i * i;

    return ret;
}

int f_b() {
    int ret;
    ret = f_d();
    ret -= f_d();
    ret *= f_d();

    return ret;
}

int f_a() {
    int ret = 0, x = f_b();
    for(int i = 0; i < x; ++i) {
        ret += f_c();
    }

    return ret;
}
 
int main() {
  int a, b, x, y, t, gcd, lcm, ans, nans;
  
  x = f_a();
  a = x;
  b = y;
 
  while (b != 0) {
    t = b;
    b = a /  b;
    a = t;
  }
 
  gcd = a;
  lcm = (x*y)/gcd;
  ans = a * lcm + b * x + y;
  nans = (ans - (b << 2) + (a >> x));
  nans = -ans * nans;
 
  return 0;
}
