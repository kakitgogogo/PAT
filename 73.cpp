#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin>>s;
	string num;
	int p=-1,n=-1,i;
	for(i=1;i<s.size();i++)
	{
		if(s[i]=='E') break;
		if(s[i]=='.') continue;
		num+=s[i];
	}
	int ex=atoi(s.substr(i+1).c_str());
	//cout<<ex<<endl;
	string res=(s[0]=='-')?"-":"";
	if(ex<0)
	{
		int m=-ex-1;
		res+="0.";
		for(int i=0;i<m;i++) res+="0";
		res+=num;
	}
	else
	{
		int m=num.size()-1;
		if(m>ex) 
		{
			res=res+num.substr(0,ex+1)+"."+num.substr(ex+1);
		}
		else
		{
			res+=num;
			for(int i=0;i<ex-m;i++)
			{
				res+="0";
			}
		}
	}
	cout<<res;
}