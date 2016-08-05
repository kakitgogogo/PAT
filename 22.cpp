#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	map<string,vector<string> >Map[5];
	for(int i=0;i<n;i++)
	{
		string data[6];
		getline(cin,data[0]);
		for(int j=1;j<6;j++)
		{
			getline(cin,data[j]);
			if(j==3)
			{
				istringstream iss(data[j]);
				while(!iss.eof())
				{
					string word;
					iss>>word;
					Map[j-1][word].push_back(data[0]);
				}
			}
			else Map[j-1][data[j]].push_back(data[0]);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int k; 
		scanf("%d: ",&k);
		string key;
		getline(cin,key);
		printf("%d: %s\n",k,key.c_str());
		
		k-=1;
		vector<string>res;
		if(Map[k].find(key)==Map[k].end()) printf("Not Found\n");
		res=Map[k][key];
		sort(res.begin(),res.end());
		for(int j=0;j<res.size();j++) cout<<res[j]<<endl;
	}
}