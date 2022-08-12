#include <iostream>
using namespace std;
struct node{
    int h;
    int l;
    int r;
}plat[1001];
int n;
int dfs(int x){
    for(int i=1;i<=n;++i){
        if(plat[x].l>plat[i].l && plat[x].h > plat[i].h){
            
        }
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>plat[i].h>>plat[i].l>>plat[i].r;
    }
    for(int i=1;i<=n;++i){
        dfs(i);
    }
    return 0;
}
