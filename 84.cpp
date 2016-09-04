#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
//#include <boost/unordered_set.hpp>
#include <unordered_set>
using namespace std;
//using namespace boost;

int main()
{
	char s[85],t[85];
	scanf("%s",s);
	scanf("%s",t);
	int s_len=strlen(s);
	int t_len=strlen(t);
	unordered_set<char>Set;
	for(int i=0;i<t_len;i++)
	{
		char c=toupper(t[i]);
		Set.insert(c);
	}
	for(int i=0;i<s_len;i++)
	{
		char c=toupper(s[i]);
		if(Set.find(c)==Set.end())
		{
			printf("%c",c);
			Set.insert(c);
		}
	}
}
