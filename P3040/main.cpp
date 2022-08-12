#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=21;
int n;
int w[maxn];
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
int max3(int x,int y,int z){
    return max(x,max(y,z));
}
int ans=2e9;
void dfs(int x,int y,int z,int q){
    if(x>=ans || y>=ans || z>=ans){
        return ;
    }
    if(q>n){
        ans=max3(x,y,z);
        return ;
    }
    dfs(x+w[q],y,z,q+1);
    dfs(x,y+w[q],z,q+1);
    dfs(x,y,z+w[q],q+1);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        w[i]=read();
    }
    sort(w+1,w+1+n);
    reverse(w+1,w+n+1);
    dfs(0,0,0,1);
    cout<<ans;
    return 0;
}
