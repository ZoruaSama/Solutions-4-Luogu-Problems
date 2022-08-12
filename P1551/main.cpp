#include <iostream>
using namespace std;
int par[5001];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
int main() {
    int n,m,p;
    cin>>n>>m>>p;
    while(n){
        par[n]=n;
        n--;
    }
    while(m--){
        int i,j;
        cin>>i>>j;
        par[find(i)]=find(j);
    }
    while(p--){
        int i,j;
        cin>>i>>j;
        if(find(i)==find(j)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
