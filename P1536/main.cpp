#include <iostream>
using namespace std;
int par[1001];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
int main() {
    int n,m;
    freopen("P1536_1.in","r",stdin);
    do{
        cin>>n;
        if(n==0){
            break;
        }
        cin>>m;
        for(int i=1;i<=n;++i){
            par[i]=i;
        }
        int cnt=0;
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            if(find(x)!=find(y)){
                par[find(x)]=find(y);
                cnt++;
            }
        }
        cout<<n-1-cnt<<endl;
    }while(true);
    return 0;
}
