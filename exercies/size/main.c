#include <float.h>
#include <limits.h>
#include <stdio.h>

#define TESTBIT 2

int main() {
  char ch, chtest;
  unsigned char uchar;
  short sh, shtest;
  unsigned short ush;
  long l, ltest;
  unsigned long lu;
  long long ll;
  unsigned long long llu;
  float f, ftest, flast;
  double db, dbtest, dblast;

  ch = uchar = chtest = sh = shtest = ush = l = ltest = lu = ll = llu = 0;
  ch++;
  sh++;
  l++;
  ll++;

  f = ftest = db = dbtest = 0.0;

  while (chtest >= 0) {
    chtest = ch * TESTBIT;
    ch = chtest;
  }

  // ch = ch * TESTBIT;

  printf("Min char: %d, %d\n", ch, SCHAR_MIN);
  --ch;
  printf("Max char: %d, %d\n", ch, SCHAR_MAX);

  --uchar;
  printf("Min unsigned char: 0, 0\n");
  printf("Max unsigned char: %d, %d\n", uchar, UCHAR_MAX);

  while (shtest >= 0) {
    shtest = sh * TESTBIT;
    sh = shtest;
  }

  printf("Min short: %d, %d\n", sh, SHRT_MIN);
  --sh;
  printf("Max short: %d, %d\n", sh, SHRT_MAX);

  --ush;
  printf("Min unsigned short: 0, 0\n");
  printf("Max unsigned short: %d, %d\n", ush, USHRT_MAX);

  while (ltest >= 0) {
    ltest = l * TESTBIT;
    l = ltest;
  }

  printf("Min long: %ld, %ld\n", l, LONG_MIN);
  --l;
  printf("Max long: %ld, %ld\n", l, LONG_MAX);

  --lu;
  printf("Min unsigned long: 0, 0\n");
  printf("Max unsigned long: %lu, %lu\n", lu, ULONG_MAX);

  while (ll >= 0) {
    ll = ll * TESTBIT;
  }

  printf("Min long long: %lld, %lld\n", ll, LLONG_MIN);
  ll--;
  printf("Max long long: %lld, %lld\n", ll, LLONG_MAX);

  llu--;
  printf("Min long long: 0, 0\n");
  printf("Max long long: %llu, %llu\n", llu, ULLONG_MAX);

  while (f == 0.0) {
    flast = ftest;
    ftest = ftest + 1113e28;
    f = (f + ftest) - ftest;
  }

  printf("Min float (calc): 0.0\n");
  printf("Min float (header): %f\n", FLT_MIN);

  printf("Max float (calc): %f\n", flast);
  printf("Max float (header): %f\n", FLT_MAX);

  while (db == 0.0) {
    dblast = dbtest;
    dbtest = dbtest + 1105e298;
    db = (db + dbtest) - dbtest;
  }

  printf("Max double (calc): %fd\n", dblast);
  printf("Max double (header): %fd\n", DBL_MAX);

  printf("Double difference: %fd\n", DBL_MAX - dblast);

  return 0;
}
