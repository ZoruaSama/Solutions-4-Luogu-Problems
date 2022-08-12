#include <iostream>
#include <queue>
using namespace std;
queue<int> xp;
queue<int> yp;
int main() {
    int n,m;
    char mp[101][101]={0};
    int xx[]={-1,0,+1,0};
    int yy[]={0,+1,0,-1};
    int color[101][101]={0};
    int c=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
            mp[i][j]-=48;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(color[i][j]==0 && mp[i][j]>0){
                c++;
                xp.push(i);
                yp.push(j);
                while(!xp.empty()){
                    color[xp.front()][yp.front()]=c;
                    for(int k=0;k<4;++k){
                        int nx=xp.front()+xx[k];
                        int ny=yp.front()+yy[k];
                        if(nx>0 && ny>0 && nx<=n && ny<=m && mp[nx][ny]>0 && color[nx][ny]==0){
                            xp.push(nx);
                            yp.push(ny);
                        }
                    }
                    xp.pop();
                    yp.pop();
                }
            }
        }
    }
    cout<<c-1;
    return 0;
}
