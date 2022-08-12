#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int m,n;
int dm[3];
int sx,sy;
int mp[31][31];
bool vis[31][31]={false};
int dx[]={-1,+1,-2,+2,-1,+1,-2,+2};
int dy[]={+2,+2,+1,+1,-2,-2,-1,-1};

struct p{
    int x,y,t;
};
queue<p> q;
int main() {
    //freopen("P2385_2.in","r",stdin);
    cin>>m>>n>>dm[1]>>dm[2];
    for(int i=0;i<8;++i){
        dx[i] = dx[i]/abs(dx[i])*dm[abs(dx[i])];
        dy[i] = dy[i]/abs(dy[i])*dm[abs(dy[i])];
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
            if(mp[i][j]==3){
                q.push(p{i,j,0});
                vis[i][j]=true;
            }else if(mp[i][j]==4){
                sx=i;sy=j;
            }else if(mp[i][j]==2){
                mp[i][j]=0;
            }
        }
    }
    //q.push(p{,,0});
    while(!q.empty()){
        p now=q.front();
        q.pop();
        if(now.x==sx && now.y==sy){
            cout<<now.t;
            break;
        }else {
            for(int i=0;i<8;++i){
                int nx=now.x+dx[i];
                int ny=now.y+dy[i];
                if(nx>=1 && ny>=1 && nx<=m && ny<=n && mp[nx][ny]!=0 && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    q.push(p{nx,ny,now.t+1});
                }
            }
        }
    }
    return 0;
}


//while(!q.empty()){
//p now=q.front();
//q.pop();
//if(now.x==sx && now.y==sy && now.t%2==0){
//cout<<now.t/2;
//break;
//}else{
//for(int i=1;i<=2;++i){
//if(now.t%2 == 1 && now.l == i){
//continue ;
//}
//for(int j=0;j<4;++j){
//if(now.t%2 == 1 && now.d == j%2){
//continue ;
//}
//int nx=now.x+dm[i]*dx[j];
//int ny=now.y+dm[i]*dy[j];
//if(nx>=1 && ny>=1 && nx<=m && ny<=n && mp[nx][ny]!=0 && !vis[nx][ny]){
//if(now.t%2==0){
//vis[nx][ny]=true;
//}
//q.push(p{nx,ny,now.t+1,i,j%2});
//}
//}
//}
//}
//}
