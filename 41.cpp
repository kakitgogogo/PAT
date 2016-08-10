#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int count[100001];
	vector<int>nums;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		if(count[num]==0) nums.push_back(num);
		count[num]++;
	}
	bool flg=true;
	for(int i=0;i<nums.size();i++)
	{
		if(count[nums[i]]==1&&flg) 
		{
			cout<<nums[i];
			flg=false;
		}
	}
	if(flg) cout<<"None";
}