#include <iostream>
using namespace std;
const int maxn=1e4+10;
short f[maxn][maxn];
short vis[maxn][maxn];
int t,x,y,Mod;
int cal(){
    return (x+y)%Mod;
}
int dfs(int n){
    if(vis[x][y]==maxn-t){
        return 0;
    }else{
        vis[x][y]=maxn-t;
    }
    if(f[x][y]!=0){
        return f[x][y];
    }
    if(n==1){
        if((x=cal())!=0){
            dfs(2);
        }else{
            return f[x][y]=1;
        }

    }else{
        if((y=cal())!=0){
            dfs(1);
        }else{
            return f[x][y]=2;
        }
    }
}
int main() {
    cin>>t>>Mod;
    while(t--){
        cin>>x>>y;
        int res=dfs(1);
        if(res!=0){
            cout<<dfs(1)<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
    return 0;
}
