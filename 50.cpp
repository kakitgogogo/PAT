#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    string res;
    bool isvalid[1000];
    memset(isvalid,true,1000);
    for(int i=0;i<t.size();i++)
    {
        isvalid[int(t[i])]=false;
    }
    for(int i=0;i<s.size();i++)
    {
        if(isvalid[int(s[i])])
        {
            res+=s[i];
        }
    }
    cout<<res;
}
