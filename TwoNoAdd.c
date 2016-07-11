#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *a;
	int b;
	scanf("%d",(int *)&a);
	scanf("%d",&b);
	printf("%d",&a[b]);
	puts("!!!Hello Archbloom!!!"); /* prints !!!Hello Archbloom!!! */
	return EXIT_SUCCESS;
}
