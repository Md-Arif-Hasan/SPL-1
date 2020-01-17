#include<stdio.h>
int main()
{
	FILE *file = fopen("Euation.c","r");
	int line =0;
	char input[512];

	while(fgets(input,512,file))
	{
		line++;
		printf("Line: %d -> %s",line,input);
	}

	printf("\n End of Program\n");
	fclose(file);
	return 0;
}
