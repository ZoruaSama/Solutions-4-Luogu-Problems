#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=3e5+10;
int n;
char dj;
double f[maxn];
double l[maxn];
int main() {
    //freopen("in","r",stdin);
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i){
        scanf("%c",&dj);
        //cout<<dj<<endl;
        if(dj=='o'){
            f[i]=f[i-1]+l[i-1]*2+1;
            l[i]=l[i-1]+1;
        }else if(dj=='x'){
            f[i]=f[i-1];
            l[i]=0;
        }else if(dj=='?'){
            f[i]=f[i-1]+(l[i-1]*2+1)*0.5;
            l[i]=(l[i-1]+1)/2;
        }
    }
    printf("%.4lf",f[n]);
    return 0;
}
