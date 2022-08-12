#include <iostream>
#include <cstdio>
int n,p;
int a[10086]={0};
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
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
     a[x]+=v;
}

using namespace std;


int main() {
    n=read();
    p=read();
    int c,last=0;
    for(int i=1;i<=n;++i){
        c=read();
        add(i,c-last);
        last=c;
    }
    for(int i=1;i<=p;++i){
        int x,y,z;
        x=read();
        y=read();
        z=read();
        add(x,z);
        add(y+1,-z);
    }
    int res=2e9;
    int sum=0;
    for(int i=1;i<=n;++i){
        sum+=a[i];
        res=min(sum,res);
    }
    cout<<res;
    return 0;
}
