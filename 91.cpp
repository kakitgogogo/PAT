#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

int m,n,l,t;
vector<vector<vector<int> > >a;
vector<vector<vector<bool> > >isvis;

int dir1[6]={1,0,0,-1,0,0};
int dir2[6]={0,1,0,0,-1,0};
int dir3[6]={0,0,1,0,0,-1};
/*
void dfs(int i,int j,int k,int &count)
{
	isvis[i][j][k]=true;
	count++;
	for(int p=0;p<6;p++)
	{
		int x=i+dir1[p],y=j+dir2[p],z=k+dir3[p];
		if(x>=0&&y>=0&&z>=0&&x<l&&y<m&&z<n&&!isvis[x][y][z]&&a[x][y][z]==1)
		{
			dfs(x,y,z,count);
		}
	}
}
*/

struct point
{
	int x,y,z;
	point(int xx,int yy,int zz):x(xx),y(yy),z(zz){}
};

int main()
{
	cin>>m>>n>>l>>t;
	a.resize(l,vector<vector<int> >(m,vector<int>(n,0)));
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				cin>>a[i][j][k];
			}
		}
	}
	isvis.resize(l,vector<vector<bool> >(m,vector<bool>(n,false)));
	int res=0;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(!isvis[i][j][k]&&a[i][j][k]==1)
				{
					int count=0;
					//dfs(i,j,k,count);
					queue<point>que;
					que.push(point(i,j,k));
					isvis[i][j][k]=true;
					while(!que.empty())
					{
						point tmp=que.front();
						que.pop();
						count++;
						for(int p=0;p<6;p++)
						{
							int x=tmp.x+dir1[p],y=tmp.y+dir2[p],z=tmp.z+dir3[p];
							if(x>=0&&y>=0&&z>=0&&x<l&&y<m&&z<n&&!isvis[x][y][z]&&a[x][y][z]==1)
							{
								isvis[x][y][z]=true;
								que.push(point(x,y,z));
							}
						}
					}
					if(count>=t) res+=count;
				}
			}
		}
	}
	cout<<res;
}