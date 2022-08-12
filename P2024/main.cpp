#include <iostream>
using namespace std;
const int maxn=5e4+10;
int n,k;
int ans;
int par[maxn*3];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
int merge(int x,int y){
    if(x>y){
        merge(y,x);
    }else{
        par[find(x)]=find(y);
    }
}

int main() {
    cin>>n>>k;
    int c,x,y;
    for(int i=1;i<=n*3;++i){
        par[i]=i;
    }
    for(int i=1;i<=k;++i){
        cin>>c>>x>>y;
        if(x>n || y>n){
            ans++;
            continue;
        }
        if(c==1){
            if(find(x)==find(y+n)||find(x+n)==find(y)){
                ans++;
                continue;
            }
            merge(x,y);
            merge(x+n,y+n);
            merge(x+n+n,y+n+n);
        }else{
            if(find(x)==find(y)||find(x)==find(y+n)){
                ans++;
                continue;
            }
            merge(x+n,y);
            merge(x+n+n,y+n);
            merge(x,y+n+n);
        }
    }
    cout<<ans;
    return 0;
}
