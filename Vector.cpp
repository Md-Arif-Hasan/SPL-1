#include<bits/stdc++.h>
using namespace std;
int mian()
{

	vector<int>v;
	vector<int>::iterator i;
	vector<int>::reverse_iterator ri;

	v.assign(5,100);

	for(int j=1;j<=10;j++)
	{
		v.push_back(j);
	}
	i=v.begin();
	v.insert(i+5,23); //add(insert) the value 23 at the index 5..!
	v.erase(i+2);  //delete the value of index 2..!

	cout<<v.size()<<endl;//size of the vector by counting the elements ;
	cout<<v.max_size()<<endl; //max size of the vector(huge) ;
	cout<<v.empty()<<endl;  // return a boolean value(ans of this Q) about:"is it a empty verctor?"
	cout<<v.capacity()<<endl;

	sort(v.begin(),v.end()); // sort in ascending order123...
	sort(v.rbegin(),v.rend()); // sort in decending ortder321...

/*	for(int j=0;j!=v.size();j++)
	{
		cout<<v[j]<<" "<<endl;
	}
	 while(1)
     {
         cin>>i;
         if(i==-1)
            break;
         a[p]=i;
         p++;
     }
     sort(a,a+p);//for sort from 0 to a+p(LAST INDEX)
*/

	for(i=v.begin(); i!=v.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;

		for(ri=v.rbegin(); ri!=v.rend();ri++)
	{
		cout<<*ri<<" ";
	}
	return 0;
}
