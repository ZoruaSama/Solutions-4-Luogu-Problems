#include <iostream>
#include <cmath>
using namespace std;
int n,q;
const int maxn=50001;
int maxi[maxn][19]={0};
int mini[maxn][19]={0};
int ij[maxn]={0};
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
int main() {
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        mini[i][0]=maxi[i][0]=read();
    }
    for(int i=1;i<=n;++i){
        ij[i] = (int)log2(i);
    }
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            mini[i][j]=min(mini[i][j-1],mini[i+(1<<(j-1))][j-1]);
            maxi[i][j]=max(maxi[i][j-1],maxi[i+(1<<(j-1))][j-1]);
        }
    }
    int a,b;
    for(int i=1;i<=q;++i){
        a=read();
        b=read();
        int k = ij[b-a+1];
        int ansmax = max(maxi[a][k],maxi[b-(1<<k)+1][k]);
        int ansmin = min(mini[a][k],mini[b-(1<<k)+1][k]);
        write(ansmax-ansmin);
        puts("");

    }
    return 0;
}
