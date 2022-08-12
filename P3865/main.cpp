#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
// d[i][j]表示：左端点为i 长度为2^j的区间的最值
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
int d[100001][17]={0};
int ij[100001]={0};
int main() {
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        d[i][0]=read();
    }
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            d[i][j]=max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=100001;++i){
        ij[i] = (int)log2(i);
    }
    for(int i=1;i<=m;++i){
        int l=read();
        int r=read();
        int k=ij[r-l+1];
        printf("%d\n",max(d[l][k],d[r-(1<<k)+1][k]));
    }
    return 0;
}
