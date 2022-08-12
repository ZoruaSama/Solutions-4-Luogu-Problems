#include <iostream>
#include <algorithm>
#include <cstdio>
int minn=101;
int maxn=-1;
int sum=0;
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
    int n;
    n=read();
    for(int i=1;i<=n;++i){
        int score;
        score=read();
        minn = min(minn,score);
        maxn = max(maxn,score);
        sum +=score;
        if(i>=3){
            printf("%.2lf\n",(sum-minn-maxn)*1.0/(i-2));
        }
    }
    return 0;
}
