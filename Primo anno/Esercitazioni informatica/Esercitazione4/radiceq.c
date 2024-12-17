#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char * argv[]) {
  float  x = 137.512;
  double y = 137.512;

  printf ("Float : %lf\n", sqrt(x));
  printf ("Double: %lf\n", sqrt(y));

  printf ("--------- Seconda parte ------------\n\n");
  x = 0.1;
  y = 0.1;
  printf ("%.20f\n", x);
  printf ("%.20lf\n", y);
  printf ("%.20lf\n", sqrt(x));
  printf ("%.20lf\n", sqrt(y));
  exit(EXIT_SUCCESS);
}
