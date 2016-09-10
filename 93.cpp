#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin>>s;
	long long num_p=0,num_pa=0,num_pat=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='T')
		{
			num_pat+=num_pa;
		}
		else if(s[i]=='A')
		{
			num_pa+=num_p;
		}
		if(s[i]=='P')
		{
			num_p++;
		}
	}
	cout<<num_pat%1000000007<<endl;
}