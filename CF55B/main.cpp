#include <iostream>
using namespace std;
int n[5];
char s[4];
bool vis[5];
int ans=2e9;
int cal(int x,int y,int c){
    if(c=='*'){
        return x*y;
    }else{
        return x+y;
    }
}
void dfs(int x){
    if(x>3){
        for(int i=1;i<=4;++i){
            if(!vis[i]){
                ans=min(ans,n[i]);
            }
        }
    }
    for(int i=1;i<=4;++i){
        if(n[i]>ans && !vis[i]){
            return ;
        }
    }
    for(int i=1;i<=4;++i){
        if(!vis[i]){
            for(int j=i+1;j<=4;++j){
                if(!vis[j]){
                    int m = n[i];
                    n[i]=cal(n[i],n[j],s[x]);
                    vis[j]=true;
                    dfs(x+1);
                    vis[j]=false;
                    n[i]=m;
                }
            }
        }
    }
}
int main() {
    for(int i=1;i<=4;++i){
        cin>>n[i];
    }
    for(int i=1;i<=3;++i){
        cin>>s[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
