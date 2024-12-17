#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main() {
  printf ("INT_MAX: %d\n", INT_MAX);
  printf ("INT_MIN: %d\n", INT_MIN);
  printf ("LONG_MAX: %ld\n", LONG_MAX);
  printf ("LONG_MIN: %ld\n", LONG_MIN);
  printf ("FLT_MAX: %f\n", FLT_MAX);
  printf ("FLT_MIN: %.38f\n", FLT_MIN);
  printf ("DBL_MAX: %e\n", DBL_MAX);
  printf ("DBL_MIN: %e\n", DBL_MIN);
  printf ("FLT_EPSILON: %.38f\n", FLT_EPSILON);
  printf ("DBL_EPSILON: %e\n", DBL_EPSILON);

  exit(EXIT_SUCCESS);
}
