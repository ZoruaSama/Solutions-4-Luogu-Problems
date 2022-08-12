#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
struct t{
    int v;
    int l,r;
}T[maxn<<2];
void update(int x){

}
void build(int x,int l,int r){
    T[x].l=l;T[x].r=r;
    if(l==r){
        T[x].v=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    update(x);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    sort(a+1,a+1+n);

    return 0;
}
