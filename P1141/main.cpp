#include <iostream>
#include <queue>
using namespace std;
int mp[1001][1001];
queue<int> x;
queue<int> y;
int n,m;
int xx[]={-1,0,+1,0};
int yy[]={0,+1,0,-1};

int vis[1001][1001]={0};
int color[100002];
int id=1;
int bfs(int a,int b){
    int cnt=0;
    x.push(a);
    y.push(b);
    cnt++;
    if(vis[a][b]>0){
        return color[vis[a][b]];
    }
    vis[a][b]=id;
    while(!x.empty()){
        for(int i=0;i<4;++i){
            int nx=x.front()+xx[i];
            int ny=y.front()+yy[i];
            if(nx>0 && nx<=n && ny>0 && ny<=n && mp[nx][ny]==1-mp[x.front()][y.front()] && vis[nx][ny]==0){
                cnt++;
                x.push(nx);
                y.push(ny);
                vis[nx][ny]=id;
            }
        }
        x.pop();
        y.pop();
    }
    color[id]=cnt;
    id++;
    return cnt;
}
int main() {
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>c;
            mp[i][j]=c-48;
        }
    }
    int a,b;
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        cout<<bfs(a,b)<<endl;
    }
    return 0;
}
