#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int findChar(char*, char toFind);

int main()
{
    FILE *fptr;
    char filename[30];
    char ch[20];

    vector<char*>v[10];
    vector<char*>::iterator ittr;


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
        //printf("%s\n",ch);

        for(int i=0; i<10; i++)
        {
            if(!strcmp(ch,array[i]))
            {
                count++;
                fscanf(fptr,"%[^\n]s",ch);
                ch[strlen(ch)-1]='\0';
                if(!findChar(ch,'('))
                {
                    char *token = strtok(ch,",");
                    while(token!='\0')
                    {
                        printf("%s\n",token);
                        token = strtok(NULL, ",");
                        //v[i].push_back(0);
                    }
                }

//                char cha = fgetc(fptr);
//                while(cha!='\n')
//                {
//                    if(cha==','||cha==';')
//                    {
//                        intCount1++;
//                    }
//                    if(cha=='(')
//                        break;
//                    cha = fgetc(fptr);
//                }
            }
        }
    }

//    for(int j=1;j<=10;j++)
//	{
//		v.push_back(j);
//	}
//
//    for(ittr=v[i].begin(); ittr!=v[i].end(); ittr++)
//    {
//        cout<<*ittr<<"\n";
//        i++;
//    }
//    cout<<endl;


    //printf("Count : %d", intCount1);
    fclose(fptr);

}


int findChar(char findFrom[], char toFind)
{
    int i=0;
    while(findFrom[i]!='\0')
    {
        if(findFrom[i]==toFind)
            return 1;
        i++;
    }
    return 0;
}
