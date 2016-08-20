#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

multiset<int>s1,s2;
int mid;

void adjust()
{
	multiset<int>::iterator it;
	if(s1.size()<s2.size())
	{
		it=s2.begin();
		s1.insert(*it);
		s2.erase(it);
	}
	if(s1.size()>s2.size()+1)
	{
		it=s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if(!s1.empty())
	{
		it=s1.end();
		it--;
		mid=*it;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	stack<int>sta;
	for(int i=0;i<n;i++)
	{
		char s[15];
		scanf("%s",s);
		if(strcmp(s,"Push")==0)
		{
			int num;
			scanf("%d",&num);
			sta.push(num);
			if(s1.empty()) s1.insert(num);
			else if(num<=mid) s1.insert(num);
			else s2.insert(num);
			adjust();
		}
		else if(strcmp(s,"Pop")==0)
		{
			if(sta.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				int tmp=sta.top();
				printf("%d\n",tmp);
				sta.pop();			
				if(tmp<=mid)
				{
					s1.erase(s1.find(tmp));
				}
				else
				{
					s2.erase(s2.find(tmp));
				}
				adjust();
			}
		}
		else if(strcmp(s,"PeekMedian")==0)
		{
			if(sta.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n",mid);
			}
		}
		else
			printf("Invalid\n");
	}
}
