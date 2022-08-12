#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct trans{
    int sx,sy,zx,zy;
};
map<char,trans> tele;
char mp[300][300];
bool vis[300][300];
// # 玉米
// . 草地
// A-Z 装置
// = 出口
// @ 起点
int sx,sy;
void change(int &x,int &y,char al){
        trans t = tele[al];
        if(x==t.sx && y==t.sy){
            x = t.zx;
            y = t.zy;
        }
        else{
            x = t.sx;
            y = t.sy;
        }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='@'){
                sx=i;sy=j;
            }else if(isalpha(mp[i][j])){
                if(!tele.count(mp[i][j])){
                    tele[mp[i][j]].sx = i;
                    tele[mp[i][j]].sy = j;
                }else{
                    tele[mp[i][j]].zx = i;
                    tele[mp[i][j]].zy = j;
                }
            }
        }
    }
    queue<int> qx;
    queue<int> qy;
    queue<int> step;
    qx.push(sx);
    qy.push(sy);
    step.push(0);
    vis[sx][sy]=true;
    int xx[]={-1,0,+1,0};
    int yy[]={0,-1,0,+1};
    while(!qx.empty()){
        if(mp[qx.front()][qy.front()]=='='){
            cout<<step.front();
            return 0;
        }
        for(int i=0;i<4;++i){
            int nx = qx.front() + xx[i];
            int ny = qy.front() + yy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && mp[nx][ny]!='#' && !vis[nx][ny]){
                vis[nx][ny]=true;
                if(isalpha(mp[nx][ny])) change(nx,ny,mp[nx][ny]);
                qx.push(nx);qy.push(ny);
                step.push(step.front()+1);
            }
        }


        qx.pop();qy.pop();step.pop();
    }
    return 0;
}
