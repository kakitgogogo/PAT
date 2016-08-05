#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct testee
{
	string id;
	int location;
	int score;
};

bool cmp(const testee &t1,const testee &t2)
{
	if(t1.score!=t2.score) return t1.score>t2.score;
	else return t1.id<t2.id;
}

int main()
{
	int n;
	cin>>n;
	vector<testee>testees;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			testee t;
			t.location=i;
			cin>>t.id>>t.score;
			testees.push_back(t);
		}
	}
	sort(testees.begin(),testees.end(),cmp);
	int m=testees.size();
	cout<<m<<endl;
	vector<int>local_rank(n+1,1);
	vector<int>score(n+1,1000);
	vector<int>count(n+1,1);
	int rank=1;
	//cout<<testees[0].id<<" 1 "<<testees[0].location<<" 1"<<endl;
	for(int i=0;i<m;i++)
	{
		int loc=testees[i].location,lrank;
		if(i==0) rank=1;
		else if(testees[i].score<testees[i-1].score) rank=i+1;
		if(testees[i].score<score[loc])
		{
			lrank=local_rank[loc]=count[loc];
			score[loc]=testees[i].score;
		}
		else
		{
			lrank=local_rank[loc];
		}
		count[loc]++;
		cout<<testees[i].id<<" "<<rank<<" "<<testees[i].location<<" "<<lrank<<endl;
	}
}