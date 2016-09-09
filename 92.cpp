#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

int main()
{
	string s,t;
	cin>>s>>t;
	multiset<char>Set;
	for(int i=0;i<s.size();i++) Set.insert(s[i]);
	bool isok=true;
	int count=0;
	multiset<char>::iterator it;
	for(int i=0;i<t.size();i++)
	{
		it=Set.find(t[i]);
		if(it==Set.end())
		{
			isok=false;
			count++;
		}
		else
		{
			Set.erase(it);
		}
	}
	if(isok)
	{
		printf("Yes %d\n",s.size()-t.size());
	}
	else
	{
		printf("No %d\n",count);
	}
} 