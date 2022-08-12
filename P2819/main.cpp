#include <iostream>
using namespace std;
int n,k,m;
bool mp[101][101]={false};
int color[101]={0};
int cnt=0;
void dfs(int p){
    if(p==n+1){
        cnt++;
//        for(int i=1;i<=n;i++){
//            cout<<color[i]<<' ';
//        }
//        cout<<endl;
        return ;
    }
    for(int i=1;i<=m;i++){
        int j;
        for(j=0;j<n;j++){
            if(mp[p][j]){
                if(i==color[j]){
                    break;
                }
            }
        }
        if(j==n){
            color[p]=i;
            dfs(p+1);
            color[p]=0;
        }
    }
}
int main() {
    cin>>n>>k>>m;
    for(int i=0;i<k;i++) {
        int u, v;
        cin >> u >> v;
        mp[u][v] = true;
        mp[v][u] = true;
    }
    dfs(1);
    cout<<cnt;
    return 0;
}
