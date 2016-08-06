#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student
{
	int id;
	string name;
	int grade;
};

bool cmp1(const student &s1,const student &s2)
{
	return s1.id<s2.id;
}

bool cmp2(const student &s1,const student &s2)
{
	if(s1.name!=s2.name) return s1.name<s2.name;
	else return s1.id<s2.id;
}

bool cmp3(const student &s1,const student &s2)
{
	if(s1.grade!=s2.grade) return s1.grade<s2.grade;
	else return s1.id<s2.id;
}

int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	vector<student>students(n);
	for(int i=0;i<n;i++)
	{
		char name[9];
		scanf("%d %s %d",&students[i].id,name,&students[i].grade);
		students[i].name=name;
	}
	if(c==1) sort(students.begin(),students.end(),cmp1);
	else if(c==2) sort(students.begin(),students.end(),cmp2);
	else sort(students.begin(),students.end(),cmp3);
	for(int i=0;i<n;i++)
	{
		printf("%06d %s %d\n",students[i].id,students[i].name.c_str(),students[i].grade);
	}
}