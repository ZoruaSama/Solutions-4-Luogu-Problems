#include <iostream>
using namespace std;

const int maxx=10001;
int par[maxx]={0};
int par_[maxx]={0};


int find(int x){
    return x==par[x]? x : par[x]=find(par[x]);
}

int find_(int x){
    return x==par_[x]? x : par_[x]=find_(par_[x]);
}

int main() {
    freopen("P2078_2.in","r",stdin);
    int n,m,r,q;
    int cnt=0,cnt_=0;
    cin>>n>>m>>r>>q;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        par_[i]=i;
    }
    for(int i=1;i<=r;++i){
        int x,y;
        cin>>x>>y;
        if(find(x)!=find(y)){
            if(find(x)>find(y)){
                swap(x,y);
            }
            par[find(x)]=find(y);
        }
    }
    for(int i=1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        x=-x;
        y=-y;
        if(find_(x)!=find_(y)){
            if(find_(x)>find_(y)){
                swap(x,y);
            }
            par_[find_(x)]=find_(y);
        }
    }
    for(int i=1;i<=n;++i){
        cnt+=(find(i)==find(1));
    }
    for(int i=1;i<=m;++i){
        cnt_+=(find_(i)==find_(1));
    }
    cout<<min(cnt,cnt_);
//    cout<<cnt<<' '<<cnt_;
    return 0;
}