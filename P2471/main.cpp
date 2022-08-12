#include <iostream>
using namespace std;
const int maxn=5e4+10;
int n,m;
int rr[maxn];
int yy[maxn];
struct t{
    int v;
    int l,r;
}T[maxn*4];
void update(int x){
    T[x].v=max(T[x<<1].v,T[x<<1|1].v);
}
void build(int x,int l,int r){
    T[x].l=l;T[x].r=r;
    if(l==r){
        T[x].v = rr[l];
//        cout<<"rr"<<l<<' '<<rr[l]<<endl;
        return ;
    }
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    update(x);
}
int query(int x,int l,int r){
    if(l<=T[x].l && T[x].r<=r){
        return T[x].v;
    }
    int res=0;
    int mid=(T[x].l+T[x].r)/2;
    if(l<=mid){
        res=max(res,query(x<<1,l,r));
    }else if(r>mid){
        res=max(res,query(x<<1|1,l,r));
    }
    return res;
}
int find(int x){
    for(int i=1;i<=n;++i){
        if(yy[i]==x){
            return i;
        }
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>yy[i];
        cin>>rr[i];
    }
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;++i){
        int y,x;
        cin>>y>>x;
        y=find(y);
        x=find(x);
        cout<<y+1<<' '<<x<<endl;
        cout<<query(1,y+1,x)<<' '<<rr[x]<<endl;
    }
    return 0;
}
