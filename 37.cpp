#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int nc;
	cin>>nc;
	vector<int>p_cou;
	vector<int>n_cou;
	for(int i=0;i<nc;i++)
	{
		int c;
		cin>>c;
		if(c>=0) p_cou.push_back(c);
		else n_cou.push_back(-c);
	}
	int np;
	cin>>np;
	vector<int>p_pro;
	vector<int>n_pro;
	for(int i=0;i<np;i++)
	{
		int p;
		cin>>p;
		if(p>=0) p_pro.push_back(p);
		else n_pro.push_back(-p);
	}
	sort(p_cou.begin(),p_cou.end(),greater<int>());
	sort(n_cou.begin(),n_cou.end(),greater<int>());
	sort(p_pro.begin(),p_pro.end(),greater<int>());
	sort(n_pro.begin(),n_pro.end(),greater<int>());
	int res=0;
	for(int i=0;i<p_cou.size()&&i<p_pro.size();i++)
	{
		res+=p_cou[i]*p_pro[i];
	}
	for(int i=0;i<n_cou.size()&&i<n_pro.size();i++)
	{
		res+=n_cou[i]*n_pro[i];
	}
	cout<<res;
}