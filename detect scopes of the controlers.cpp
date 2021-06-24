#include<bits/stdc++.h>
using namespace std;

int strToInt(string str)
{
    int r=0;
    for( int i =0; i<str.size(); i++)
    {
        r *=10;
        r+= str[i]-'0';
    }
    return r;
}


//       inzamam       //
int totalLine = 0;
struct scope {
      int startLine;
      int endLine;
      string keyword;

};
vector < string > codeWord[ 100 ];
vector < string > wordType[ 100 ];
vector < scope > scopeInfo;

void scoping( int startLine, int endLine )
{
      stack < pair < int, string > > ss;
      string lastKeyword;

      for ( int LN = startLine; LN <= endLine; ++LN ) {
            for ( int CL = 0; CL < codeWord[ LN ].size(); ++CL ) {
                  if ( wordType[ LN ][ CL ] == "keyword" )
                        lastKeyword = codeWord[ LN ][ CL ];

                  if ( codeWord[ LN ][ CL ] == "{" )
                        ss.push( { LN, lastKeyword } );

                  if ( codeWord[ LN ][ CL ] == "}" ) {
                        scope sc;
                        sc.startLine = ss.top().first;
                        sc.keyword = ss.top().second;
                        sc.endLine = LN;
                        ss.pop();
                        scopeInfo.push_back( sc );
                  }
            }
      }
}

struct stm {
int lineN;
string operatorr;
} ;

vector< stm > stateInfo ;

void statement(int startLine, int endLine)
{
      // vector< pair< int,string > > states;
      for(int LN = startLine; LN <= endLine ; ++LN)
      {
            for(int CL= 0; CL< codeWord[LN].size(); CL++)
            {
                  if(codeWord[LN][CL] == "=")
                  {
                    stm info;
                    info.lineN = LN;
                    info.operatorr = codeWord[LN][CL];
                    stateInfo.push_back(info);
                  }
            }
      }
}

void statePrint()
{
      for(int i=0; i<stateInfo.size() ; i++)
      {
         cout<<stateInfo[i].lineN <<"-> (" <<stateInfo[i].operatorr <<")"<< endl;
      }

}


void scopePrint()
{
      for ( int i = 0; i < scopeInfo.size(); ++i ) {
            cout << "(" << scopeInfo[ i ].startLine << ", " << scopeInfo[ i ].endLine << ") -> " << scopeInfo[ i ].keyword << "\n";
      }
}


int main()
{
    FILE *fp;
    string str, codeText;
    char ch;
    stack <int> s1;

    fp = fopen( "output.txt", "r" );

    if ( fp == NULL )
    {
        printf( "error while opening the file\n" );
        exit( 0 );
    }

    while ( ( ch = fgetc( fp ) ) != EOF )
    {
        codeText = codeText + ch;
    }

    stringstream X( codeText );
    while ( getline( X, str, '\n' ) )
    {
        string strg1,strg2,strg3,strg4;

        stringstream Y( str );
        getline( Y, strg1, '\t' );
        getline( Y, strg2, '\t' );
        getline( Y, strg3, '\t' );
        getline( Y, strg4, '\t' );

        int line = strToInt( strg3 );

        codeWord[ line ].push_back( strg2 );
        wordType[ line ].push_back( strg1 );

        totalLine = max( totalLine, line );
    }

    scoping( 1, totalLine );
    scopePrint();
    statement(1, totalLine);
    statePrint();

}


/// https://ideone.com/hkTTIa




