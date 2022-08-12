#include <iostream>
#include <queue>
using namespace std;
char mp[1001][1001];
bool vis[1001][1001]={false};
int cnt=0;
int main() {
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=r-1;++i){
        for(int j=1;j<=c-1;++j){
                if((mp[i][j]=='#')+(mp[i+1][j+1]=='#') + (mp[i][j+1]=='#') + (mp[i+1][j]=='#') == 3){
                    cout<<"Bad placement.";
                    return 0;
                }
        }
    }
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            if(mp[i][j]=='#' && !vis[i][j]){
                cnt++;
                vis[i][j]=true;
                queue<int> x;
                queue<int> y;
                x.push(i);
                y.push(j);
                int xx[]={-1,0,+1,0};
                int yy[]={0,+1,0,-1};
                while(!x.empty()){
                    for(int k=0;k<4;++k){
                        int nx=x.front()+xx[k];
                        int ny=y.front()+yy[k];
                        if(nx>0 && ny>0 && nx<=r && ny<=c && !vis[nx][ny] && mp[nx][ny]=='#'){
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
    cout<<"There are "<<cnt<<" ships.";
    return 0;
}
