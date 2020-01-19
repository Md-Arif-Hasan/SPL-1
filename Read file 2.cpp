#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fptr;
	char filename[30];
	char ch;
	int count =0,i=0,result;
	char a1[5],b1[]="char",c1[]="int";
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
/*
		if(ch=';')
        {
            ch++;
            while(ch !=' ')
            {
               ch++;
                a1[i];
                i++;
            }

            if(strcmp(a1, b1)==0)
            {
                printf("Same String !");
            }

        }
*/
	}

	printf("Count : %d", count);
	fclose(fptr);

}
