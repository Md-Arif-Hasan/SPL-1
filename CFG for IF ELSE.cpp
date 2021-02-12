#include<bits/stdc++.h>
using namespace std;
#define maxLine 10000
struct line{
    string str;
    int lineNumber;
};
vector<line>vp;

vector<int>adjacencyList[maxLine+1];

stack<int>ifIndex;
stack<int>elseIndex;
vector<pair<string,int> >nestedOrNot;

int containsIf(line L){
    stringstream sStream(L.str);
    string word;
    while(getline(sStream,word,' ')){
        if(word=="if")return L.lineNumber;
    }
    return -1;
}
int containsElse(line L){
    stringstream sStream(L.str);
    string word;
    while(getline(sStream,word,' ')){
        if(word=="else")return L.lineNumber;
    }
    return -1;
}
int containsSecondBracket(line L){
    stringstream sStream(L.str);
    string word;
    while(getline(sStream,word,' ')){
        if(word=="}")return L.lineNumber;
    }
    return -1;
}
void makeNodes(line L){
    int idx1 = containsIf(L);
    int idx2 = containsSecondBracket(L);
    int idx3 = containsElse(L);
    if(idx1!=-1){
        nestedOrNot.push_back({"if",idx1});
    }
    else if(idx2!=-1){
        nestedOrNot.push_back({"}",idx2});
    }
    else if(idx3!=-1){
        nestedOrNot.push_back({"else",idx3});
    }
}
void makeEdges(){
    int Size = nestedOrNot.size();
    stack<pair<string,int> >forCalculation;
    for(int i=0;i<Size;i++){
        if(nestedOrNot[i].first!="}"){
            if(!forCalculation.empty()){
                adjacencyList[forCalculation.top().second].push_back(nestedOrNot[i].second);
            }
            forCalculation.push(nestedOrNot[i]);
        }
        else{
            forCalculation.pop();
        }
    }
}
void printList(int currLineNumber){
    for(int i=0;i<currLineNumber;i++){
        ///cout<<adjacencyList[i].size()<<" ";
        for(int j=0;j<adjacencyList[i].size();j++){
            cout<<i+1<<" "<<adjacencyList[i][j]+1<<"\n";//
        }
    }
}

int main()
{
    std::ifstream file("code2.cpp");
    std::string s;
    //cout<<"Asdasd";
    ///return 0;
    
    int lineNum = 0;
    while (getline(file, s))
    {
        line newLine;
        newLine.str = s;
        newLine.lineNumber = lineNum;
        lineNum++;
        makeNodes(newLine);
        /*if(!makeNodes(newLine)){
            makeEdges(newLine); 
        }*/
        ///cout<<containsIf(newLine)<<" "<<containsSecondBracket(newLine)<<"\n";
    }
    //cout<<lineNum<<"\n";
    //return 0;
    makeEdges();
    printList(lineNum);
    return 0;
}
