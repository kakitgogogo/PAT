#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();
	string res;
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		reverse(s.begin(),s.end());
		if(i==0)
		{
			res=s;
			continue;
		}
		int j=0;
		for(j;j<s.size()&&j<res.size();j++)
		{
			if(s[j]!=res[j]) break;
		}
		res=res.substr(0,j);
	}
	reverse(res.begin(),res.end());
	if(res.empty()) cout<<"nai"<<endl;
	else cout<<res<<endl;
}