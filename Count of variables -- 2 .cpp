#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fptr;
	char filename[30];
	char ch[20];


	char array[][30] = { "int", "char", "double","float","long double", "long int","long long int","unsigned long long int","long long int","unsigned short int" };




	int count =0,i=0,result;
    int intCount = 0;
    int intCount1 = 0;
	printf("Enter the filename to be opened :\n");
	scanf("%s",filename);

	fptr = fopen (filename,"r");

	if(  fptr == NULL)
	{
		printf("Cannot open this file !");
		exit(0);
	}


	while(fscanf(fptr,"%s",ch)!=EOF)
	{
		printf("%s\n",ch);

		for(int i=0;i<10;i++)
        {
           	if(!strcmp(ch,array[i]))
		{
			count++;

			char cha = fgetc(fptr);
			while(cha!='\n'){
                if(cha==','||cha==';'){
                    intCount1++;
                }
                if(cha=='(')break;
                cha = fgetc(fptr);
			}

		}
        }

	}

	printf("Count : %d", intCount1);
	fclose(fptr);

}
