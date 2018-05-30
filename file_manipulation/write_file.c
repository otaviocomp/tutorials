#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;						//pointer to a file
	fp = fopen("file.txt", "w");	//open a file

	//verify if the file was open with sucess
	if(fp == NULL)
	{
		printf("Error!");
		exit(1);
	}

	fprintf(fp, "test");			//write the word "test" in the file
	fclose(fp);						//close the file 
	return 0;
}
