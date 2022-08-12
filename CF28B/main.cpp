#include <iostream>
using namespace std;
const int maxn=110;
int n;
int par[maxn];
int goal[maxn];
int d;
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int merge(int x,int y){
    par[find(x)]=find(y);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        par[i]=i;
        cin>>goal[i];
    }
    for(int i=1;i<=n;++i){
        cin>>d;
        if(i-d>=1){
            merge(i,i-d);
        }
        if(i+d<=n){
            merge(i,i+d);
        }
    }
    for(int i=1;i<=n;++i){
        if(find(goal[i])!=find(i)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
