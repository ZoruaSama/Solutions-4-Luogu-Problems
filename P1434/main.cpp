#include <iostream>
#include <algorithm>
using namespace std;
int mp[101][101]={0};
int ans[101][101]={0};
int dx[]={0,0,-1,+1};
int dy[]={-1,+1,0,0};

int r,c;
int dps(int x,int y){
    int maxn=1;
    if(ans[x][y]>0){
        return ans[x][y];
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<r && ny<c && mp[x][y]>mp[nx][ny]){
            maxn = max(maxn,dps(nx,ny)+1);
        }
    }
    return ans[x][y] = maxn;
}
int main() {
    cin>>r>>c;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>mp[i][j];
        }
    }
    int res =0;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            res = max(res,dps(i,j));
        }
    }
    cout<<res;
    return 0;
}
