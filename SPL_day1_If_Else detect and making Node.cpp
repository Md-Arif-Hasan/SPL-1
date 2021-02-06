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
bool makeNodes(line L){
	int idx = containsIf(L);
	if(idx!=-1){
		///cout<<idx<<"\n";
		ifIndex.push(idx);
		return true;
	}
	else{
		idx = containsElse(L);
		if(idx!=-1){
			ifIndex.push(idx);
			return true;
		}
	}
	return false;
}
bool makeEdges(line L){
	int idx = containsSecondBracket(L);
	if(idx!=-1){
		if(ifIndex.empty()){
			return false;
		}
		int idxIf = ifIndex.top();
		ifIndex.pop();
		///cout<<idxIf<<" "<<idx<<"\n";
		adjacencyList[idxIf].push_back(idx);
		return true;
	}
	return false;
}
void printList(int currLineNumber){
	for(int i=0;i<currLineNumber;i++){
		///cout<<adjacencyList[i].size()<<" ";
		for(int j=0;j<adjacencyList[i].size();j++){
			cout<<i+1<<"th if ends in "<<adjacencyList[i][j]+1<<"th line\n";//
		}
	}
}

int main()
{
    std::ifstream file("code.cpp");
    std::string s;
	
    int lineNum = 0;
    while (getline(file, s))
    {
        line newLine;
        newLine.str = s;
        newLine.lineNumber = lineNum;
        lineNum++;
        if(!makeNodes(newLine)){
        	makeEdges(newLine);	
		}
        ///cout<<containsIf(newLine)<<" "<<containsSecondBracket(newLine)<<"\n";
    }
    printList(lineNum);
}
