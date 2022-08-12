#include <iostream>
#include <queue>
using namespace std;
int xx[]={0,-1,0,+1};
int yy[]={-1,0,+1,0};
int main() {
    int mp[32][32]={0};
    int vis[32][32]={0};
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    queue<int> x;
    queue<int> y;
    x.push(0);
    y.push(0);
    while(!x.empty()){
        for(int i=0;i<4;++i){
            int a = x.front()+xx[i];
            int b = y.front()+yy[i];
            if(a>=0 && a<=n+1 && b>=0 && b<=n+1 && mp[a][b]==0 && vis[a][b]!=1){
                x.push(a);
                y.push(b);
                vis[a][b]=1;
            }
        }
        x.pop();
        y.pop();
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(vis[i][j]!=1 && mp[i][j]==0){
                cout<<2;
            }
            else{
                cout<<mp[i][j];
            }
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
