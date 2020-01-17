#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr;
	char filename[30];
	char ch;
	int count =0;
	printf("Enter the filename to be opened :\n");
	scanf("%s",filename);
	
	fptr = fopen (filename,"r");
	
	if(  fptr == NULL)
	{
		printf("Cannot open this file !");
		exit(0);
	}
	
	ch = fgetc(fptr);
	
	while( ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc( fptr);
		if(ch==',')
		{
			count++;
		}
	}
	
	printf("Count : %d", count);
	fclose(fptr);

}
