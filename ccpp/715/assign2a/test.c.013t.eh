
;; Function void h() (_Z1hv, funcdef_no=3, decl_uid=2701, cgraph_uid=3)

void h() ()
{
  GIMPLE_NOP
  return;
}



;; Function void f() (_Z1fv, funcdef_no=2, decl_uid=2700, cgraph_uid=2)

void f() ()
{
  int c;
  int b;
  int a;

  a = 10;
  b = 10;
  c = 10;
  a = c;
  return;
}



;; Function void g() (_Z1gv, funcdef_no=1, decl_uid=2699, cgraph_uid=1)

void g() ()
{
  f ();
  h ();
  return;
}



;; Function int main() (main, funcdef_no=0, decl_uid=2702, cgraph_uid=0)

int main() ()
{
  long int lcm;
  long int gcd;
  long int t;
  long int y;
  long int x;
  long int b;
  long int a;
  int D.2730;
  long int D.2729;
  long int D.2728;
  long int D.2727;
  long int D.2726;
  long int D.2725;
  bool D.2724;

  a = x;
  b = -1300900;
  a = a + 1;
  goto <D.2722>;
  <D.2723>:
  t = b;
  g ();
  f ();
  b = a / b;
  a = t;
  <D.2722>:
  D.2724 = b != 0;
  if (D.2724 != 0) goto <D.2723>; else goto <D.2721>;
  <D.2721>:
  f ();
  f ();
  gcd = a;
  D.2725 = x * y;
  D.2726 = a - b;
  lcm = D.2725 / D.2726;
  D.2727 = a + b;
  D.2728 = D.2727 + x;
  D.2729 = D.2728 + y;
  t = D.2729 + t;
  D.2730 = 0;
  goto <D.2731>;
  D.2730 = 0;
  goto <D.2731>;
  <D.2731>:
  return D.2730;
}


