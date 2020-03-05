#include<bits/stdc++.h>
using namespace std;

vector<string>vp;


// Check whether the line contains any datatype or not !
bool datatype(string s)
{
    map<string,int>mp;
    int i=0,j=0;
    vector <string> tokens;


    string word, token ;

    // Tokenizing w.r.t. comma
    stringstream check1(s);
    while(getline(check1, word, ','))
    {
        stringstream check2(word);
        // Tokenizing w.r.t. comma
        while(getline(check2, token, ' '))
        {
            //cout<<token<<endl;;
            tokens.push_back(token);
        }
    }

        for(i=0; i<tokens.size(); i++)
        {
            mp[tokens[i]]++;
        }


    if(mp["int"]>=1||mp["double"]>=1||mp["char"]>=1||mp["float"]>=1 || mp["void"]>=1 )
        return true;
    else
        return false;
}


// Check whether the line contains any datatype or not !
//bool datatype(string s)
//{
//    map<string,int>mp;
//    vector<string>vs;
//    int sz=s.size();
//    int i=0, j=0;
//
//    for(i=0; i<sz; i++)
//    {
//        if(s[i]==' ')
//        {
//            string sb=s.substr(j,i-j);
//            vs.push_back(sb);
//            while(i<sz&&s[i]==' ')
//                i++;
//            j=i;
//        }
//    }
//    string sb=s.substr(j,i-j);
//    vs.push_back(sb);
//    for(i=0; i<vs.size(); i++)
//        mp[vs[i]]++;
//
//    if(mp["int"]>=1||mp["double"]>=1||mp["char"]>=1||mp["float"]>=1 || mp["void"]>=1)
//        return true;
//    else
//        return false;
//}


bool checkfunc(string s)
{
    int opening=0,ending=0;
    for(int j=0; j<s.size(); j++)
    {
        if(s[j]=='(')
            opening++;
        if(s[j]==')')
            ending++;
    }
    if(opening==1&&ending==1)
        return true;
    else
        return false;
}


string printFuncName(string s){
	string restr;
	map<string,int>mp;
	mp["int"]++;mp["float"]++;mp["double"]++;mp["char"]++; mp["void"]++;
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(flag==0){
			restr.push_back(s[i]);
			if(mp[restr]==1){
				flag=1;
				restr.clear();
			}
		}
		else if(flag==1&&s[i]!='('){
			 if(s[i]!=' ')
			   restr.push_back(s[i]);
		}
		else if(flag==1&&s[i]=='('){
			return restr;
		}
	}
}



void printVaribaleName(string s)
{
    int i=0;
    int j=0;
    string s1;
    while(s[i]!='(')
        i++;
    i++;
    int cnt=0;
    while(i<s.size())
    {
        if(s[i]!=')'&&s[i]!=' '&&s[i]!=',')
        {
            s1.push_back(s[i]);
        }
        else if(s1.size()!=0)
        {
            cout<<s1;
            cnt++;
            if(cnt%2==0)
                cout<<endl;
            else
                cout<<' ';
            s1.clear();
        }
        i++;
    }
}


void printNormalVariable(string s)
{
    int i=0,j=0;
    vector <string> tokens;
    stringstream check1(s);

    string word, token ;

    // Tokenizing w.r.t. space ' '
    while(getline(check1, word, ','))
    {
        stringstream check2(word);
        while(getline(check2, token, ' '))
        {
            //cout<<token<<endl;;
            tokens.push_back(token);
        }
    }

    //  Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << " ";
    }
cout<<endl;
}

int main()
{
    std::ifstream file("D.cpp");
    std::string s;

    while (std::getline(file, s))
    {
        if(datatype(s))
            vp.push_back(s);
    }

    for(int i=0; i<vp.size(); i++)
    {
        if(checkfunc(vp[i]))
        {
            cout<<endl<<"*** Function name : " <<printFuncName(vp[i])<<endl;
            printVaribaleName(vp[i]);
        }
        else
        {
            //cout<<vp[i]<<endl;
            cout<<endl;
            printNormalVariable(vp[i]);
        }
    }
}
