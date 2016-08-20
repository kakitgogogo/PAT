#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <boost/unordered_map.hpp>
using namespace std;
using namespace boost;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	unordered_map<int,int>Map;
	int Max=0,res;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			int b=++Map[a];
			if(b>Max)
			{
				Max=b;
				res=a;
			}
		}
	}
	printf("%d",res);
}