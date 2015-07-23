
;; Function int main() (main, funcdef_no=0, decl_uid=2699, cgraph_uid=0)

int main() ()
{
  int j;
  int i;
  int h;
  int d;
  int c;
  int b;
  int a;
  int D.2731;
  bool D.2729;
  bool D.2721;
  int h.3;
  int h.2;
  int h.1;
  bool retval.0;

  scanf ("%d", &h);
  goto <D.2710>;
  <D.2711>:
  h.3 = h;
  if (h.3 != 0) goto <D.2716>; else goto <D.2717>;
  <D.2716>:
  goto <D.2719>;
  <D.2720>:
  if (b < c) goto <D.2722>; else goto <D.2723>;
  <D.2722>:
  d = 100;
  goto <D.2724>;
  <D.2723>:
  d = 50;
  <D.2724>:
  <D.2719>:
  D.2721 = a <= 49;
  if (D.2721 != 0) goto <D.2720>; else goto <D.2718>;
  <D.2718>:
  goto <D.2725>;
  <D.2717>:
  i = 0;
  goto <D.2730>;
  <D.2728>:
  j = j + i;
  i = i + 1;
  <D.2730>:
  D.2729 = i < d;
  if (D.2729 != 0) goto <D.2728>; else goto <D.2726>;
  <D.2726>:
  <D.2725>:
  <D.2710>:
  h.1 = h;
  retval.0 = h.1 != 0;
  h.2 = h.1 - 1;
  h = h.2;
  if (retval.0 != 0) goto <D.2711>; else goto <D.2709>;
  <D.2709>:
  D.2731 = 0;
  goto <D.2734>;
  <D.2734>:
  h = {CLOBBER};
  goto <D.2732>;
  D.2731 = 0;
  goto <D.2732>;
  <D.2732>:
  return D.2731;
  <D.2733>:
  h = {CLOBBER};
  resx 1
}


