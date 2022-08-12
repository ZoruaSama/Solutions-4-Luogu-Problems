#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e5+10;
struct t{
    int v,maxt,mint;
    int l,r;
    int la;
    int lmin;
}T[maxn*4];
short data[maxn];
int n,m;
string s;
int len(int x){
    return T[x].r-T[x].l+1;
}
void update(int x){
    T[x].v = T[x<<1].v + T[x<<1|1].v;
}
void build(int x,int l,int r){
    T[x].l=l;T[x].r=r;
    if(l==r){
        T[x].v=data[l];
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
void change(int x,int l,int r,int v,int k){
    if(l<=T[x].l && T[x].r<=r){
        brush(x,v);
        return ;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    if(l<=mid){
        change(x<<1,l,r,v,k);
    }
    if(r>mid){
        change(x<<1|1,l,r,v,k);
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
    for(int i=1;i<=n;++i){
        scanf("%d",&data[i]);
    }
    build(1,1,n);
    int op,l,r;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            change(1,l,r,1,2e9);
        }else if(op==2){
            printf("%d\n",query(1,l,r));
        }else if(op==3){

        }else if(op==4){

        }else if(op==5){

        }
    }
    return 0;
}