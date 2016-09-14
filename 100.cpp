#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
	int n;
	cin>>n;
	getchar();
	
	map<string,int>Map1,Map2;
	for(int i=0;i<13;i++)
	{
		Map1[low[i]]=i;
		Map2[high[i]]=i;
	}
	
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		if(isdigit(s[0]))
		{
			int num=atoi(s.c_str());
			int l=num%13,h=num/13;
			if(l==0&&h==0) cout<<"tret"<<endl;
			else if(l==0) cout<<high[h]<<endl;
			else if(h==0) cout<<low[l]<<endl;
			else cout<<high[h]<<" "<<low[l]<<endl;
		}
		else
		{
			int idx=0;
			while(s[idx]!=' '&&idx<s.size()) idx++;
			int h=0,l=0;
			if(idx==s.size())
			{
				if(Map1.find(s)!=Map1.end()) l=Map1[s];
				else h=Map2[s];
			}
			else
			{
				h=Map2[s.substr(0,idx)];
				l=Map1[s.substr(idx+1)];
			}
			cout<<h*13+l<<endl;
		}
	}
}