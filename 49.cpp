#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    string n;
    cin>>n;
    int res=0;
    for(int i=0;i<n.size();i++)
    {
        int mid=n[i]-'0';
        int left=atoi(n.substr(0,i).c_str());
        int right=atoi(n.substr(i+1,n.size()).c_str());
        int ex=n.size()-i-1;
        if(mid==0) res+=left*pow(10,ex);
        else if(mid==1) res+=((right+1)+left*pow(10,ex));
        else res+=(left+1)*pow(10,ex);
    }
    cout<<res;
}
