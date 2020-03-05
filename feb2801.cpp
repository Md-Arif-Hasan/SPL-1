#include<bits/stdc++.h>
using namespace std;
vector<string>vp;
bool datatype(string s){
	map<string,int>mp;
	vector<string>vs;
	int sz=s.size();
	int j=0;
	int i;
	for(i=0;i<sz;i++){
		if(s[i]==' '){
			string sb=s.substr(j,i-j);
			vs.push_back(sb);
			while(i<sz&&s[i]==' ')
			i++;
			j=i;
		}
	}
	string sb=s.substr(j,i-j);
	vs.push_back(sb);
	for(i=0;i<vs.size();i++)
	mp[vs[i]]++;
	string teststr1="int";
	string teststr2="double";
	string teststr3="float";
	string teststr4="char";
	if(mp[teststr1]>=1||mp[teststr2]>=1||mp[teststr3]>=1||mp[teststr4]>=1)
		return true;
	else
		return false;
}
bool checker(string s){
	       int opening=0,ending=0;
	  	   for(int j=0;j<s.size();j++){
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
string checker2(string s){
	string restr;
	map<string,int>mp;
	mp["int"]++;mp["float"]++;mp["double"]++;mp["char"]++;
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
void checker3(string s){
    int i=0;
    int j=0;
    string s1;
    while(s[i]!='(')
    i++;
    i++;
    int cnt=0;
    while(i<s.size()){
    	if(s[i]!=')'&&s[i]!=' '&&s[i]!=','){
    		s1.push_back(s[i]);
		}
		else if(s1.size()!=0){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	for(i=0;i<1;i++){
		 string s;
	     getline(cin,s);
	     if(datatype(s))
	        vp.push_back(s);
	 }
	  for(i=0;i<vp.size();i++){
	  	   if(checker(vp[i])){
			  cout<<checker2(vp[i])<<endl;
			  checker3(vp[i]);
		  }
	  }
}
/*we have to print the frequency of a in a string given in input
read a string 
iterate over every position and count its frequency like arr[s[i]-'a']++
then print arr[0]
for(i=0;i<26;i++)
cout<<arr[i]<<" ";
*/
