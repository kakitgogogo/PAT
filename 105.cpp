#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end(),greater<int>());
	
	int w=sqrt(n);
	while(n%w!=0) w--;
	int h=n/w;
	vector<vector<int> >b(h,vector<int>(w));
	int l=0,r=w-1,u=0,d=h-1;
	int idx=0;
	while(l<r&&u<d)
	{
		for(int i=l;i<=r;i++) b[u][i]=a[idx++];
		for(int i=u+1;i<=d;i++) b[i][r]=a[idx++];
		for(int i=r-1;i>=l;i--) b[d][i]=a[idx++];
		for(int i=d-1;i>=u+1;i--) b[i][l]=a[idx++];
		l++;r--;
		u++;d--;
	}
	if(l==r) 
	{
		for(int i=u;i<=d;i++) b[i][l]=a[idx++];
	}
	else if(u==d)
	{
		for(int i=l;i<=r;i++) b[u][i]=a[idx++];
	}
	for(int i=0;i<h;i++)
	{
		cout<<b[i][0];
		for(int j=1;j<w;j++)
		{
			cout<<" "<<b[i][j];
		}
		cout<<endl;
	}
}