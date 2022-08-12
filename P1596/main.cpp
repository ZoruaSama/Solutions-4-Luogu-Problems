#include <iostream>
using namespace std;
int xx[]={-1,-1,-1,0,0,+1,+1,+1};
int yy[]={-1,+1,0,-1,+1,-1,+1,0};
int n,m;
char mp[100][100];
void dfs(int x,int y){
    for(int i=0;i<8;++i){
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx>=0 && nx<n && ny>=0 && ny <m && mp[nx][ny] == 'W'){
            mp[nx][ny]='.';
            dfs(nx,ny);
        }
    }
}
int main() {
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='W'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
    return 0;
}
