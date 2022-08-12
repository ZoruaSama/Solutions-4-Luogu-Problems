#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int d[100001][18]={0};
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}
int ask(int m,int n);
void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
int k=0;
int main() {
    int n=read();
    int m=read();
    for(int i=1;i<=n;++i){
        d[i][0] = read();
    }
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
    k = (int) log2(m);
    for(int i=1;i<=n-m+1;++i){
        write(ask(i,i+m-1));
        puts("");
    }
    return 0;
}
int ask(int m,int n){
    return min(d[m][k],d[n-(1<<k)+1][k]);
}
