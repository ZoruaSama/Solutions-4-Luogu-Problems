#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
struct t{
    int v;
    int l,r;
    int la;
}T[maxn*4];
int n,m;
int len(int x){
    return T[x].r-T[x].l+1;
}
void update(int x){
    T[x].v = T[x<<1].v + T[x<<1|1].v;
}
void build(int x,int l,int r){
    T[x].l=l;T[x].r=r;
    if(l==r){
        T[x].v=0;
        return ;
    }
    int mid=(T[x].l+T[x].r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    update(x);
}
void brush(int x,int v){
    T[x].la^=v;
    T[x].v=len(x)-T[x].v;
}
void push_down(int x){
    if(T[x].la){
        brush(x<<1,T[x].la);
        brush(x<<1|1,T[x].la);
        T[x].la=0;
    }
}
void change(int x,int l,int r,int v){
    if(l<=T[x].l && T[x].r<=r){
        brush(x,v);
        return ;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    if(l<=mid){
        change(x<<1,l,r,v);
    }
    if(r>mid){
        change(x<<1|1,l,r,v);
    }
    update(x);
}
int query(int x,int l,int r){
    if(l<=T[x].l && T[x].r<=r){
        return T[x].v;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    int res=0;
    if(l<=mid){
        res+=query(x<<1,l,r);
    }
    if(r>mid){
        res+=query(x<<1|1,l,r);
    }
    return res;
}
int main() {
    scanf("%d%d",&n,&m);
    build(1,1,n);
    int op,l,r;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&op,&l,&r);
        if(op==0){
            change(1,l,r,1);
        }else{
            printf("%d\n",query(1,l,r));
        }
    }
    return 0;
}
