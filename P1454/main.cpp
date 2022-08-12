#include <iostream>
#include <queue>
using namespace std;
char mp[101][101];
bool vis[101][101]={false};
int cnt=0;
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(mp[i][j]=='#' && !vis[i][j]){
                cnt++;
                vis[i][j]=true;
                queue<int> x;
                queue<int> y;
                x.push(i);
                y.push(j);
                int xx[]={-1,0,+1,0,-2,0,+2,0,+1,-1,+1,-1};
                int yy[]={0,+1,0,-1,0,+2,0,-2,+1,+1,-1,-1};
                while(!x.empty()){
                    for(int k=0;k<13;++k){
                        int nx=x.front()+xx[k];
                        int ny=y.front()+yy[k];
                        if(nx>0 && ny>0 && nx<=n && ny<=m && !vis[nx][ny] && mp[nx][ny]=='#'){
                            vis[nx][ny]=true;
                            x.push(nx);
                            y.push(ny);
                        }
                    }
                    x.pop();
                    y.pop();
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
