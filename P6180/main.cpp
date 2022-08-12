#include <iostream>
#include <cstdio>
using namespace std;
int n,q;
int qzh[4][100001]; //品种 长度

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
int ask(int a,int b,int pz){
    return qzh[pz][b]-qzh[pz][a-1];
}
int main() {
    n=read();q=read();
    for(int i=1;i<=n;++i){
        int pz=read();
        for(int j=1;j<=3;++j) qzh[j][i]=qzh[j][i-1];
        qzh[pz][i]++;
    }
    for(int i=1;i<=q;++i){
        int a,b;
        a=read();b=read();
        write(ask(a,b,1));
        putchar(' ');
        write(ask(a,b,2));
        putchar(' ');
        write(ask(a,b,3));
        cout<<endl;
    }
    return 0;
}
