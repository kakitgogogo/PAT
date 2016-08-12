#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>coins(n);
	for(int i=0;i<n;i++)
	{
		cin>>coins[i];
	}
	sort(coins.begin(),coins.end());
	int l=0,r=n-1;
	while(true)
	{
		while(coins[l]+coins[r]>m)
		{
			r--;
			if(l>=r) 
			{
				cout<<"No Solution";
				return 0;
			}
		}
		if(coins[l]+coins[r]==m) 
		{
			cout<<coins[l]<<" "<<coins[r];
			return 0;
		}
		while(coins[l]+coins[r]<m)
		{
			l++;
			if(l>=r) 
			{
				cout<<"No Solution";
				return 0;
			}
		}
		if(coins[l]+coins[r]==m) 
		{
			cout<<coins[l]<<" "<<coins[r];
			return 0;
		}
	}
	
}