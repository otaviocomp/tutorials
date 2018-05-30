#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	FILE *image = fopen("sushi.jpg", "rb");
	FILE *out = fopen("result.jpg", "wb");

	fseek(image, 0, SEEK_END);
	int lenght = ftell(image);
	buffer = (char*)malloc(lenght + 1);
	fread(buffer, lenght, 1, image);
	fwrite(buffer, lenght, 1, out);
	fclose(image);
	fclose(out);

	//printf("content: %s\n", string);
	return 0;
}
