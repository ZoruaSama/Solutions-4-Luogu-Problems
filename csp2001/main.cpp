#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
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
struct p{
    int i;
    int s;
}ps[210];
bool cmp(p p1,p p2){
    return (p1.s<p2.s) || (p1.s==p2.s && p1.i<p2.i);
}
int main() {
    int n,ox,oy,x,y;
    n=read();
    ox=read();
    oy=read();
    for(int i=1;i<=n;++i){
        x=read();
        y=read();
        ps[i].i=i;
        ps[i].s=(x-ox)*(x-ox)+(y-oy)*(y-oy);
    }
    sort(ps+1,ps+1+n,cmp);
    for(int i=1;i<=3;++i){
        write(ps[i].i);
        puts("");
    }
    return 0;
}
