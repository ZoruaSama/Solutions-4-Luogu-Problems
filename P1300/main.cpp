#include <iostream>
using namespace std;
int h,w;
int x1,x2,y1,y2,d1;
char mp[31][31];
bool vis[31][31][4]={false};
//ESWN 0123
int xx[]={0,+1,0,-1};
int yy[]={+1,0,-1,0};
int res=2e9;

void dfs(int x,int y,int d,int cost){
    if(cost >= res){
        return ;
    }
    if(x==x2 && y==y2){
        res = min(res,cost);
    }else{
        bool flag=false;
        for(int i=0;i<4;++i){
            int nx=x+xx[i];
            int ny=y+yy[i];
            int nc;
            if(i==d){
                nc=0;
            }else if((d-1)%4==i){ //左边
                nc=1;
                d=i;
            }else if((d+1)%4==i){//右边
                nc=5;
                d=i;
            }else{
                nc=10;
                d=i;
            }
            if(nx>=1 && ny>=1 && nx<=h && ny<=w && !vis[nx][ny][d] && mp[nx][ny]=='#'){
                vis[nx][ny][d]=true;
                dfs(nx,ny,d,cost+nc);
                vis[nx][ny][d]=false;
            }
        }
    }
}
int main() {
    cin>>h>>w;
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='F'){
                x2=i;
                y2=j;
            }else if(mp[i][j]=='E'){
                x1=i;
                x1=j;
                d1=0;
            }else if(mp[i][j]=='W'){
                x1=i;
                x1=j;
                d1=1;
            }
            else if(mp[i][j]=='N'){
                x1=i;
                x1=j;
                d1=2;
            }
            else if(mp[i][j]=='S'){
                x1=i;
                x1=j;
                d1=3;
            }
        }
    }
    vis[x1][y1][d1]=true;
    dfs(x1,y1,d1,0);
    cout<<res;
    return 0;
}
