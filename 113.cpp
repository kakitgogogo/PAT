#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	
	int Min=(n%2==0)?0:1,size1=n/2;
	
	int i,sum1=0,sum2=0;
	for(i=0;i<size1;i++)
	{
		sum1+=a[i];
	}
	for(i;i<n;i++)
	{
		sum2+=a[i];
	}
	cout<<Min<<" "<<sum2-sum1<<endl;
}