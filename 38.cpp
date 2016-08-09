#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(string s1,string s2)
{
	int n=s1.size(),m=s2.size();
	if(n<=m)
	{
		while(n<m)
		{
			s1=s1+s1.substr(0,(m-n<=n)?m-n:n);
			n=s1.size();
		}
	}
	else
	{
		while(m<n)
		{
			s2=s2+s2.substr(0,(n-m<=m)?n-m:m);
			m=s2.size();
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s1[i]!=s2[i]) return s1[i]<s2[i];
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	vector<string>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end(),cmp);
	bool flg=true;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=0;j<nums[i].size();j++)
		{
			if(flg&&nums[i][j]=='0') continue;
			cout<<nums[i][j];
			flg=false;
		}
	}
	if(flg) cout<<0;
}