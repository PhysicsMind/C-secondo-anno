#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;

	c = getchar();

	while ( c != EOF ) {
		putchar(c);
		c = getchar();
	}

	exit(EXIT_SUCCESS);
}
