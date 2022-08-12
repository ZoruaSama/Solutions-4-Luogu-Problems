#include <iostream>
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

int main() {
    int n,res=0;
    n=read();
    while(n--){
        int c;
        c=read();
        res^=c; //NOLINT
    }
    cout<<res;
    return 0;
}
