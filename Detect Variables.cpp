#include<bits/stdc++.h>
using namespace std;
int findChar(char*, char toFind);
void removeChar(char *str,char ch);
int main()
{
    FILE *fptr;
    char filename[30];
    char ch[20];

    vector<string>v[4];
    vector<string>::iterator ittr;


    char array[][30] = { "int", "char", "double","float"};//,"long double", "long int","long long int","unsigned long long int","long long int","unsigned short int" };




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


        for(int i=0; i<4; i++)
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
                        //printf("%s\n",token);
                        removeChar(token,' ');
                        string a = token;
                        v[i].push_back(a);
                        token = strtok(NULL, ",");

                    }
                }
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        cout<<endl;

        printf("%s : ",array[i]);
        for(ittr=v[i].begin(); ittr!=v[i].end(); ittr++)
        {
            cout<<*ittr<<",";
        }
        cout<<endl;
    }

    fclose(fptr);
    return 0;
}

void removeChar(char *str,char ch)
{
    int newCount=0;
    for(int i=0; str[i]; i++)
    {
        if(str[i]=='='){
            str[newCount]='\0';
            break;
        }
        if(str[i]!=ch)
        {
            str[newCount++] = str[i];
        }
    }
    str[newCount]='\0';
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
