#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool ismod(string &s)
{
	bool flg=false;
	for(int i=0;i<s.size();i++)
	{
		switch(s[i])
		{
		case '1':s[i]='@';flg=true;break;
		case '0':s[i]='%';flg=true;break;
		case 'l':s[i]='L';flg=true;break;
		case 'O':s[i]='o';flg=true;break;
		default:break;
		}
	}
	return flg;
}

int main()
{
	int n;
	cin>>n;
	vector<string>ids;
	vector<string>pws;
	for(int i=0;i<n;i++)
	{
		string id,pw;
		cin>>id>>pw;
		if(ismod(pw))
		{
			ids.push_back(id);
			pws.push_back(pw);
		}
	}
	int m=ids.size();
	if(m==0)
	{
		printf("There %s %d account%s and no account is modified",(n==1)?"is":"are",n,(n==1)?"":"s");
	}
	else
	{
		cout<<m<<endl;
		for(int i=0;i<m;i++)
		{
			cout<<ids[i]<<" "<<pws[i]<<endl;
		}
	}
}