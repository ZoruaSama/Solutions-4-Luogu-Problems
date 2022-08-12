#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m,p;
struct t{
    ll sum,lm,la;
    int l,r;
}T[maxn*4];
int d[maxn];
int update(int x){
    T[x].sum=(T[x<<1].sum+T[x<<1|1].sum)%p;
}
int len(int x){
    return T[x].r-T[x].l+1;
}
void build(int x,int l,int r){
    T[x].l=l;
    T[x].r=r;
    T[x].lm=1;
    T[x].la=0;
    if(l==r){
        T[x].sum=d[l];
        return ;
    }
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    update(x);
}
void brush(int x,ll mul,ll add){
    if(mul==1 && add==0){
        return ;
    }
    T[x].sum=T[x].sum*mul+len(x)*add;
    T[x].sum%=p;
    T[x].lm*=mul; T[x].la*=mul;
    T[x].la+=add;
    T[x].lm%=p;
    T[x].la%=p;
}
void push_down(int x){
    brush(x<<1,T[x].lm,T[x].la);
    brush(x<<1|1,T[x].lm,T[x].la);
    T[x].lm=1;
    T[x].la=0;
}
void change(int x,int l,int r,ll mul,ll add){
    if(l<=T[x].l && T[x].r<=r){
        brush(x,mul,add);
        return ;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    if(l<=mid){
        change(x<<1,l,r,mul,add);
    }
    if(r>mid){
        change(x<<1|1,l,r,mul,add);
    }
    update(x);
}
ll query(int x,int l,int r){
    if(l<=T[x].l && T[x].r<=r){
        return T[x].sum;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    ll res=0;
    if(l<=mid){
        res+=query(x<<1,l,r);
    }
    if(r>mid){
        res+=query(x<<1|1,l,r);
    }
    return res%p;
}
int main() {
//    freopen("P3373_2.in","r",stdin);
//    freopen("P3373_2.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i){
        scanf("%d",&d[i]);
    }
    build(1,1,n);
    int c,x,y,k;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&c,&x,&y);
        if(c==1){
            scanf("%d",&k);
            change(1,x,y,k,0);
        }else if(c==2){
            scanf("%d",&k);
            change(1,x,y,1,k);
        }else{
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}
