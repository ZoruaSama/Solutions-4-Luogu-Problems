#include <iostream>
using namespace std;
bool vis[9]={false};
int ans=2e9;
int xx[]={-1,0,+1,0};
int yy[]={0,-1,0,+1};
int up[]={416,464,200,308,186,89,38,23,11};
void dfs(int s,int t){
    if(t>ans){
        return ;
    }
    if(s==511){
        ans=min(ans,t);
    }else{
        for(int i=0;i<9;++i){
            if(!vis[i]){
                vis[i]=true;
                dfs(s^up[i],t+1); //NOLINT
                vis[i]=false;
            }
        }
    }
}
int main() {
    int s=0;
    for(int i=0,x;i<=8;++i){
        cin>>x;
        s|=x*(1<<i); //NOLINT
    }
    dfs(s,0);
    cout<<ans;
    return 0;
}
