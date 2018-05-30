#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	FILE *image = fopen("image.jpeg", "rb");
	FILE *out = fopen("result.jpeg", "wb");

	fseek(image, 0, SEEK_END);
	int lenght = ftell(image);
	fseek(image, 0, SEEK_SET);
	buffer = (char*)malloc(lenght + 1);
	fread(buffer, lenght, 1, image);
	fwrite(buffer, lenght, 1, out);
	fclose(image);
	fclose(out);

	return 0;
}
