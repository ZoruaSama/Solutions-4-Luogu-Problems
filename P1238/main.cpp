#include <iostream>
#include <vector>
using namespace std;
int xx[]={0,-1,0,+1};
int yy[]={-1,0,+1,0};
int m,n;
int sx,sy;
int ex,ey;
int mp[15][15];
bool vis[15][15]={0};
vector<int> xp;
vector<int> yp;
bool path=false;
void dfs(int x,int y){
    if(x==ex && y==ey){
        for(int i=0;i<xp.size();++i){
            cout<<'('<<xp[i]<<','<<yp[i]<<')';
            if(i!=xp.size()-1){
                cout<<"->";
            }
        }
        path=true;
        cout<<endl;
    }
    else{
        for(int i=0;i<4;++i){
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx>0 && nx<=m && ny>0 && ny<=n && mp[nx][ny]==1 && !vis[nx][ny]){
                vis[nx][ny]=true;
                xp.push_back(nx);
                yp.push_back(ny);
                dfs(nx,ny);
                xp.pop_back();
                yp.pop_back();
                vis[nx][ny]=false;
            }
        }
    }
}
int main() {
    cin>>m>>n;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    cin>>sx>>sy>>ex>>ey;
    xp.push_back(sx);
    yp.push_back(sy);
    vis[sx][sy]=true;
    dfs(sx,sy);
    if(!path){
        cout<<-1;
    }
    return 0;
}
