#include <iostream>
int mp[21][21]={0};
bool vis[21]={false};
int n,m;
int res=-1;
using namespace std;
void dfs(int x,int s,int num){
    if(s>res){
        res=s;
    }
    if(num==n){
        return ;
    }
    for(int i=1;i<=n;++i){
        if(mp[x][i]>0 && !vis[i]){
            int c=mp[x][i];
            vis[i]=true;
            mp[x][i]=0;
            mp[i][x]=0;
            dfs(i,s+c,num+1);
            vis[i]=false;
            mp[x][i]=c;
            mp[i][x]=c;
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        cin>>mp[a][b];
        mp[b][a]=mp[a][b];
    }
    for(int i=1;i<=n;++i){
        vis[i]=true;
        dfs(i,0,0);
        vis[i]=false;
    }
    cout<<res;
    return 0;
}
