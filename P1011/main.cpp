#include <iostream>
using namespace std;
int main() {
    int up_a[21]={0,1,0};
    int down_a[21]={0,0,0,0,1,1};
    int up_u[21]={0,0,1};
    int down_u[21]={0,0,1,1,1,2};

    int a,n,m,x,u;
    /*   上车     下车      车上人数
     + 1  1a+0u   0a+0u   1a
     + 2  0a+1u   0a+1u   1a
     + 3  1a+1u   0a+1u   2a
     + 4  1a+2u   1a+1u   2a+u
     + 5  2a+3u   1a+2u   3a+2u
     + 6  3a+5u   2a+3u   4a+4u
     + 7  5a+8u   3a+5u
     + F-1  m             m
     + F    0     m     0
     */
    cin>>a>>n>>m>>x;
    for(int i=3;i<=20;++i){
        up_a[i]=up_a[i-1]+up_a[i-2];
        up_u[i]=up_u[i-1]+up_u[i-2];
    }
    for(int i=6;i<=20;++i){
        down_a[i]=down_a[i-1]+down_a[i-2];
        down_u[i]=down_u[i-1]+down_u[i-2];
    }
    int as=0,us=0;
    for(int i=1;i<=n-1;++i){
        as+=up_a[i]-down_a[i];
        us+=up_u[i]-down_u[i];
    }
    u=(m-as*a)/us;
    int res=0;
    for(int i=1;i<=x;++i){
        res+=up_a[i]*a+up_u[i]*u;
        res-=down_a[i]*a+down_u[i]*u;
    }
    cout<<res;
    return 0;
}
