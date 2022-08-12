#include <iostream>
using namespace std;
int par[2020];
int find(int x){
    return x==par[x]? x:par[x]=find(par[x]);
}
int merge(int x,int y){
    par[find(x)]=find(y);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=2*n;++i){
        par[i]=i;
    }
    for(int i=0;i<m;++i){
        char c;
        int x,y;
        cin>>c;
        if(c=='F'){
            cin>>x>>y;
            merge(x,y);
        }else if(c=='E'){
            cin>>x>>y;
            merge(x+n,y);
            merge(y+n,x);
        }
    }
    int sum=0;
    for(int i=1;i<=n;++i){
        sum += (par[i]==i);
    }
    cout<<sum;
    return 0;
}
