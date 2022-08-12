#include <iostream>
#define ll long long
using namespace std;
int a[10010];
bool vis[10010]={false};
#include <cstdio>
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
unsigned int count(unsigned int n)
{
    unsigned int c =0 ;
    for (c=0; n; ++c)
    {
        n &= (n-1) ;
    }
    return c ;
}
ll c1,c2;
int n;
ll ans=2e18;
void dfs(int left,ll cost){
    if(cost > ans){
        return ;
    }
    if(left==1){
        ans = min(ans,cost);
        return ;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        for(int j=i+1;j<=n;++j){
            if(vis[j]) continue;
            if(!vis[i] && !vis[j] && count(a[i] xor a[j])==1){
                vis[i]=true;
                dfs(left-1,cost+c1);
                vis[i]=false;
                vis[j]=true;
                dfs(left-1,cost+c1);
                vis[j]=false;
            }
            else if(!vis[i] && !vis[j] && count(a[i] xor a[j])>1){
                vis[i]=true;
                dfs(left-1,cost+c2);
                vis[i]=false;
                vis[j]=true;
                dfs(left-1,cost+c2);
                vis[j]=false;
            }
        }
    }
}
int main(){
    n=read();
    c1=read();
    c2=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    dfs(n,0);
    cout<<ans;
    return 0;
}
