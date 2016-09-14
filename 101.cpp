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
	vector<int>a(n);
	vector<int>Min(n);
	vector<int>Max(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0) 
		{
			Max[i]=a[i];
		}
		else
		{
			Max[i]=max(a[i],Max[i-1]);
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			Min[i]=a[i];
		}
		else
		{
			Min[i]=min(a[i],Min[i+1]);
		}
	}
	vector<int>res;
	for(int i=0;i<n;i++)
	{
		if(a[i]==Min[i]&&a[i]==Max[i])
		{
			res.push_back(a[i]);
		}
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		if(i==0) cout<<res[i];
		else cout<<" "<<res[i];
	}
	cout<<endl;
}