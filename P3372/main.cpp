#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
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
struct t{
    ll v;
    int l,r;
    ll lazy;
}T[maxn*4];
ll a[maxn];
int len(int x){
    return T[x].r-T[x].l+1;
}
void update(int x){
    T[x].v=T[x<<1].v+T[x<<1|1].v;
}
void build(int x,int l,int r){
    T[x].l=l;T[x].r=r;T[x].lazy=0;
    if(l==r){ //位于叶子节点，直接更新信息并且退出递归
        T[x].v=a[l];
        return ;
    }
    int mid=(T[x].l+T[x].r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    update(x);
}
void brush(int x,ll v){  //将x区间加上v
    T[x].lazy+=v;
    T[x].v+=len(x)*v;
}
void push_down(int x){  //下传懒标记
    brush(x<<1,T[x].lazy);
    brush(x<<1|1,T[x].lazy);
    T[x].lazy=0;
}
void change(int x,int l,int r,ll w){
    //线段树节点 要修改的位置 修改的值
    if(l<=T[x].l && T[x].r<=r){
        brush(x,w);
        return ;
    }
    push_down(x);
    int mid=(T[x].l+T[x].r)/2;
    if(l<=mid) change(x<<1,l,r,w);
    if(r>mid) change(x<<1|1,l,r,w);
    update(x);
}
ll query(int x,int l,int r){
    if(l<=T[x].l and T[x].r<=r){
        return T[x].v;
    }
    int mid=(T[x].l+T[x].r)/2;
    push_down(x);
    ll res=0;
    if(l<=mid){ //被左子树区间包含
        res+=query(x<<1,l,r);
    }
    if(r>mid){ //被右子树区间包含
        res+=query(x<<1|1,l,r);
    }
    return res;
}
int n,m;
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    build(1,1,n);
    for(int i=1;i<=m;++i){
        int c,x,y,k;
        c=read();
        x=read();
        y=read();
        if(c==2){
            cout<<query(1,x,y)<<endl;
        }else{
            k=read();
            change(1,x,y,k);
        }
    }
    return 0;
}