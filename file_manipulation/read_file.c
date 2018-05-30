#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char string[50];
	fp = fopen("file.txt", "r");
	fgets(string, 50, fp);

	fclose(fp);
	printf("content: %s\n", string);
	return 0;
}
	
