#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool ispal(vector<int>v)
{
	int l=0,r=v.size()-1;
	while(l<r)
	{
		if(v[l++]!=v[r--]) return false;		
	}
	return true;
}

int main()
{
	int num,base;
	cin>>num>>base;
	if(num<=1) printf("Yes\n%d",num);
	else
	{
		vector<int>digit;
		while(num>0)
		{
			digit.push_back(num%base);
			num/=base;
		}
		if(ispal(digit)) printf("Yes\n");
		else printf("No\n");
		int n=digit.size()-1;
		cout<<digit[n];
		for(int i=n-1;i>=0;i--)
		{
			cout<<" "<<digit[i];
		}
	}
}