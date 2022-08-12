#include <iostream>
#include <vector>
using namespace std;
const int maxn=105;
char mp[maxn][maxn];
int n,m;
char g;
int g_;
struct node{
    int x,y;
};
int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};
vector<node> nodes;
int main() {
    cin>>n>>m>>g;
    if(g=='^'){
        g_=0;
    }else if(g=='v'){
        g_=1;
    }else if(g=='<'){
        g_=2;
    }else if(g=='>'){
        g_=3;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='o'){
                nodes.push_back(node{i,j});
            }
        }
    }
    for(int i=0;i<nodes.size();++i){
        int nx = nodes[i].x;
        int ny = nodes[i].y;
        while(nx>=1 && ny>=1 && nx<=n && ny<=m){
            nx+=dx[g_];
            ny+=dy[g_];
            if(mp[nx][ny]=='x'){
                cout<<"GG"<<endl;
                return 0;
            }
        }
    }
    cout<<"OK"<<endl;
    return 0;
}
