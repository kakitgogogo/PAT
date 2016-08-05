#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

bool ispal(vector<int>n)
{
	int l=0,r=n.size()-1;
	while(l<r)
	{
		if(n[l++]!=n[r--]) return false;
	}
	return true;
}

vector<int> vec_plus(vector<int>n)
{
	vector<int>ret;
	int d=0;
	for(int i=0;i<n.size();i++)
	{
		int j=n.size()-i-1;
		ret.push_back((n[i]+n[j]+d)%10);
		d=(n[i]+n[j]+d)/10;
	}
	if(d==1) ret.push_back(1);
	reverse(ret.begin(),ret.end());
	return ret;
}

void vec_print(vector<int>n)
{
	for(int i=0;i<n.size();i++)
		cout<<n[i];
	cout<<endl;
}

int main()
{
	string num;
	int k;
	cin>>num>>k;
	vector<int>n;
	for(int i=0;i<num.size();i++)
	{
		n.push_back(num[i]-'0');
	}
	for(int i=0;i<k;i++)
	{
		if(ispal(n)) 
		{
			vec_print(n);
			cout<<i<<endl;
			return 0;
		}
		n=vec_plus(n);
	}
	vec_print(n);
	cout<<k<<endl;
}