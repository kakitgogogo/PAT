#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

string lower(string s)
{
	for(int i=0;i<s.size();i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}

int main()
{
	string s;
	getline(cin,s);
	map<string,int>Map;
	int i=0;
	while(i<s.size())
	{
		int j=i,count=0;
		while(isalnum(s[j++])) count++;
		string t=lower(s.substr(i,count));
		Map[t]++;
		i=j;
		while(!isalnum(s[i])) i++;
	}
	string res;
	int Max=0;
	map<string,int>::iterator it;
	for(it=Map.begin();it!=Map.end();it++)
	{
		if(it->second>Max)
		{
			Max=it->second;
			res=it->first;
		}
	}
	cout<<res<<" "<<Max;
}