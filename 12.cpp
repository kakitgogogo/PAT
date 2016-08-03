#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student
{
	string id;
	double a;
	double c;
	double m;
	double e;
	int a_rank;
	int c_rank;
	int m_rank;
	int e_rank;
};

bool cmp1(const student &s1,const student &s2)
{
	return s1.a>s2.a;
}

bool cmp2(const student &s1,const student &s2)
{
	return s1.c>s2.c;
}

bool cmp3(const student &s1,const student &s2)
{
	return s1.m>s2.m;
}

bool cmp4(const student &s1,const student &s2)
{
	return s1.e>s2.e;
}

int main()
{
	int n,m;
	cin>>n>>m;
	map<string,student>stu;
	vector<student>vec(n);
	for(int i=0;i<n;i++)
	{
		string id;
		double c,m,e,a;
		cin>>id;
		stu[id].id=id;
		cin>>c>>m>>e;
		stu[id].c=c;stu[id].m=m;stu[id].e=e;
		a=(c+m+e)/3;
		stu[id].a=a;
		
		vec[i].id=id;
		vec[i].a=a;vec[i].c=c;vec[i].m=m;vec[i].e=e;
	}

	sort(vec.begin(),vec.end(),cmp1);
	stu[vec[0].id].a_rank=1;
	int rank=1;
	for(int i=1;i<n;i++)
	{
		string id =vec[i].id;
		if(stu[id].a<stu[vec[i-1].id].a) rank=i+1;
		stu[id].a_rank=rank;
	}

	sort(vec.begin(),vec.end(),cmp2);
	stu[vec[0].id].c_rank=1;
	rank=1;
	for(int i=1;i<n;i++)
	{
		string id =vec[i].id;
		if(stu[id].c<stu[vec[i-1].id].c) rank=i+1;
		stu[id].c_rank=rank;
	}

	sort(vec.begin(),vec.end(),cmp3);
	stu[vec[0].id].m_rank=1;
	rank=1;
	for(int i=1;i<n;i++)
	{
		string id =vec[i].id;
		if(stu[id].m<stu[vec[i-1].id].m) rank=i+1;
		stu[id].m_rank=rank;
	}

	sort(vec.begin(),vec.end(),cmp4);
	stu[vec[0].id].e_rank=1;
	rank=1;
	for(int i=1;i<n;i++)
	{
		string id =vec[i].id;
		if(stu[id].e<stu[vec[i-1].id].e) rank=i+1;
		stu[id].e_rank=rank;
	}

	for(int i=0;i<m;i++)
	{
		string id;
		cin>>id;
		if(stu.find(id)==stu.end()) 
		{
			cout<<"N/A"<<endl;
		}
		else
		{
			if((stu[id].a_rank<=stu[id].c_rank)&&(stu[id].a_rank<=stu[id].m_rank)&&(stu[id].a_rank<=stu[id].e_rank))
				cout<<stu[id].a_rank<<" "<<"A"<<endl;
			else if((stu[id].c_rank<stu[id].a_rank)&&(stu[id].c_rank<=stu[id].m_rank)&&(stu[id].c_rank<=stu[id].e_rank))
				cout<<stu[id].c_rank<<" "<<"C"<<endl;
			else if((stu[id].m_rank<stu[id].a_rank)&&(stu[id].m_rank<stu[id].c_rank)&&(stu[id].m_rank<=stu[id].e_rank))
				cout<<stu[id].m_rank<<" "<<"M"<<endl;
			else cout<<stu[id].e_rank<<" "<<"E"<<endl;
		}
	}
}