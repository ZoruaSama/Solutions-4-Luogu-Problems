#include <iostream>
using namespace std;
int xx[]={-1,0,+1,0};
int yy[]={0,+1,0,-1};
int n,m;
char mp[501][501];
string res="No";
void dfs(int x,int y){
    if(res=="Yes"){
        return ;
    }
    for(int i=0;i<4;++i){
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx>=1 && ny>=1 && nx<=n && ny<=m && mp[nx][ny]!='#'){
            char c=mp[nx][ny];
            if(c=='g'){
                res = "Yes";
                return ;
            }
            mp[nx][ny]='#';
            dfs(nx,ny);
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(mp[i][j]=='s'){
                dfs(i,j);
                cout<<res;
                return 0;
            }
        }
    }
    cout<<res;
    return 0;
}
