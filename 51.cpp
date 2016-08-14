#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=0;i<k;i++)
	{
		int cur=1,flg=0;
		stack<int>s;
		for(int j=0;j<n;j++)
		{
			int a;
			cin>>a;
			while(cur<=a&&cur<=n)
			{
				s.push(cur);
				cur++;
			}
			if(!s.empty()&&s.top()==a&&s.size()<=m)
			{
				s.pop();
			}
			else
			{
				flg=1;
			}
		}
		if(flg==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
