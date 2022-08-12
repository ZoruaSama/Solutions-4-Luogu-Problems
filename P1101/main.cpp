#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
char words[101][101];
bool vis[101][101]={0};
char ans[]="yizhong";
int xx[]={0,-1,0,+1,-1,-1,+1,+1};
int yy[]={-1,0,+1,0,-1,+1,-1,+1};


void dfs(int a,int x,int y,vector<pair<int,int>> path,int drc){
    pair<int,int> xy;
    xy.first=x;
    xy.second=y;
    path.push_back(xy);
    if(a==strlen(ans)){
        for(int i=0;i<path.size();++i){
            vis[path[i].first][path[i].second]=true;
        }
        return ;
    }else{
        if(drc==-1){
            for(int i=0;i<8;++i){
                int nx = x+xx[i];
                int ny = y+yy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && words[nx][ny]==ans[a]){
                    dfs(a+1,nx,ny,path,i);
                }
            }
        }
        else{
            int nx=x+xx[drc];
            int ny=y+yy[drc];
            if(nx>=0 && ny>=0 && nx<n && ny<n && words[nx][ny]==ans[a]){
                dfs(a+1,nx,ny,path,drc);
            }
        }
    }
    path.pop_back();
}
int main() {
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>words[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(words[i][j]==ans[0])
                dfs(1,i,j,a,-1);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(vis[i][j])
                cout<<words[i][j];
            else
                cout<<'*';
        }
        if(i!=n-1)
            cout<<endl;
    }

    return 0;
}