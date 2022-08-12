#include <iostream>
#include <queue>
using namespace std;
queue<int> xp; //NOLINT
queue<int> yp; //NOLINT
queue<int> t;  //NOLINT

int main() {
    int n;
    char mp[1001][1001];
    bool vis[1001][1001]={false};
    int xx[]={-1,0,+1,0};
    int yy[]={0,+1,0,-1};
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    xp.push(x1);
    yp.push(y1);
    t.push(0);
    while(!xp.empty()){
        if(xp.front()==x2 && yp.front()==y2){
            cout<<t.front();
            break;
        }
        for(int i=0;i<4;++i){
            int nx=xp.front()+xx[i];
            int ny=yp.front()+yy[i];
            if(nx>0 && nx<=n && ny>0 && ny<=n && !vis[nx][ny] && mp[nx][ny]!='1'){
                vis[nx][ny]=true;
                xp.push(nx);
                yp.push(ny);
                t.push(t.front()+1);
            }
        }
        xp.pop();
        yp.pop();
        t.pop();
    }
    return 0;
}
