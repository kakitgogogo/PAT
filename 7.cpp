#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>vec(n);
	vector<int>part_sum(n+1,0);
	bool isAllNeg=true;
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
		if(vec[i]>=0) isAllNeg=false;
		part_sum[i+1]=part_sum[i]+vec[i];
	}
	if(isAllNeg) 
	{
		cout<<0<<" "<<vec[0]<<" "<<vec[n-1];
		return 0;
	}
	int MAX=0x80000000,left,right;
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(part_sum[j]-part_sum[i]>MAX)
			{
				MAX=part_sum[j]-part_sum[i];
				left=i;right=j;
			}
		}
	}
	cout<<MAX<<" "<<vec[left]<<" "<<vec[right-1];
}