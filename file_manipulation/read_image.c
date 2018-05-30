#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	unsigned char string[10000];
	fp = fopen("sushi.jpg", "rb");
	fgets(string, 10000, fp);

	fclose(fp);
	printf("content: %s\n", string);
	return 0;
}
