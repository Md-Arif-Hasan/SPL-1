

4 of 698
Counting of variables in a c code
Inbox
x

Arif Hasan <muhammad.arifhasan07@gmail.com>
Attachments
Tue, Jan 21, 2:53 PM (1 day ago)
to nadia

Maam, assalamualikum. I am Arif Hasan (BSSE 1112) . My homework is submitted
 below :
Attachments area

Nadia Nahar
Tue, Jan 21, 2:57 PM (1 day ago)
to me

Okay. Now add the other variable types as well. Your next homework is to identify the names of the variables. Keep those in a vector. And print the names at the end of the program.


On Tue, Jan 21, 2020 at 2:53 PM Arif Hasan <muhammad.arifhasan07@gmail.com> wrote:
Maam, assalamualikum. I am Arif Hasan (BSSE 1112) . My homework is submitted
 below :


--
Nadia Nahar
Lecturer
Institute of Information Technology
University of Dhaka

Nadia Nahar (nadia@iit.du.ac.bd)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fptr;
	char filename[30];
	char ch[20];
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

		if(!strcmp(ch,"int"))
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


		if(!strcmp(ch,"char"))
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

	printf("Count : %d", intCount1);
	fclose(fptr);

}
