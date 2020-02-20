#include<bits/stdc++.h>
using namespace std;

vector<string>v[10];
vector<string>::iterator ittr;

char array[][30] = { "int", "char", "double","float"};
char a[100][100];
int i;
struct LineStruct
{
    int lineNo;
    string LineText;
};
LineStruct Ls[100];
int countLine = 0;


void variable_Detect( string a)
{
    int j=0;
    while(1)
    {
        string file_str1,Txt;
          stringstream point1(Txt);
        while(getline(point1, file_str1, ','))
        {

             v[j].push_back(file_str1);
             j++;
        }

        j=0;
         for(ittr=v[j].begin(); ittr!=v[j].end(); ittr++)
        {
            cout<<*ittr<<",";
        }
        cout<<endl;
    }

}




int main()
{
    FILE *fp;
    string  file_str, Txt, line_str;
    char ch;

    fp = fopen("X.cpp","r");

    if(fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF)
    {
        Txt = Txt + ch;
    }
    cout<<Txt;

    stringstream point(Txt);
    while(getline(point, file_str, '\n'))
    {
        Ls[countLine].LineText = file_str;
        Ls[countLine++].lineNo = countLine;
    }

    cout<<countLine<<endl;


    for(int i=0; i<=countLine; i++)
    {
        stringstream point2(Ls[i].LineText);
        while(getline(point2, line_str, ' '))
        {
            cout<<line_str<<endl;

            string s = line_str;

            int n = s.length();

            // declaring character array
            char char_array[n + 1];

            // copying the contents of the
            // string to char array
            strcpy(char_array, s.c_str());

            int x =  strcmp("int",char_array);
            int y=strcmp("double",char_array);
            int z=strcmp("char",char_array);
            int k = strcmp("float",char_array);
            if(x==0 || y==0 || z==0 || k==0)
            {

                string c_text;
                c_text = Ls[i].LineText;
                variable_Detect(c_text);
            }
        }
        cout<<endl;
    }

    return 0;
}

