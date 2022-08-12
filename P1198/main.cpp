#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int m,d,t=0;
struct ttt{
    ll v;
    int l,r;
}T[maxn*4];
void update(int x){
    T[x].v = max(T[x<<1].v,T[x<<1|1].v);
}

int main() {
    scanf("%d%d",&m,&d);
    int c,p;
    for(int i=1;i<=m;++i){
        scanf("%c%d",&c,&p);
    }
    return 0;
}
