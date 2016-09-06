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
	long long m;
	cin>>n>>m;
	vector<long long>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	long long left=0,right=0;
	long long Max=0;
	while(true)
	{
		while(a[left]*m>=a[right]&&right<n) right++;
		Max=max(Max,right-left);
		if(right==n) break;
		while(a[left]*m<a[right]&&left<right) left++;		
	}
	cout<<Max;
}