#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
	int k;
	string s;
	cin>>k>>s;
	int n=s.size();
	bool isprob[37];
	memset(isprob,true,sizeof(isprob));
	set<char>res;
	for(int i=0;i<n;)
	{
		int j=i+1,count=1,idx;
		if(isdigit(s[i])) idx=s[i]-'0';
		else if(isalpha(s[i])) idx=s[i]-'a'+10;
		else idx=36;
		while(s[j]==s[i]&&j<n&&count<k)
		{
			count++;
			j++;
		}
		if(count==k&&isprob[idx])
		{
			res.insert(s[i]);
		}
		else if(count!=k)
		{
			isprob[idx]=false;
			res.erase(s[i]);
		}
		i=j;
	}
	
	set<char>res2=res;
	for(int i=0;i<n;i++)
	{
		if(res2.find(s[i])!=res2.end())
		{
			cout<<s[i];
			res2.erase(s[i]);
		}
		if(res2.empty()) break;
	}
	cout<<endl;
	for(int i=0;i<n;)
	{
		if(res.find(s[i])!=res.end())
		{
			cout<<s[i];
			i+=k;
		}
		else
		{
			cout<<s[i];
			i++;
		}
	}
	cout<<endl;
}