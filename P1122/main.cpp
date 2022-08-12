#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int n;
vector<int> mp[16001];
int f[16001]={0};
int res=-2e9;
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}

void dfs(int x,int fa){
    for(int i=0;i<mp[x].size();++i){
        if(mp[x][i]!=fa){
            dfs(mp[x][i],x);
            f[x]+=max(0,f[mp[x][i]]);
        }
    }
    res=max(f[x],res);
}
int main() {
    n=read();
    for(int i=1;i<=n;++i){
        f[i]=read();
    }
    for(int i=1;i<=n-1;++i){
        int a,b;
        a=read();
        b=read();
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1,0);
    write(res);
    return 0;
}
