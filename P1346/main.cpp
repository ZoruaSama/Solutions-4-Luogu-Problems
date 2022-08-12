#include <iostream>

using namespace std;
int n,a,b;
int dis[101][101];
int main() {
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dis[i][j]=2e4;
    for(int i=1;i<=n;++i)
        dis[i][i]=0;
    for(int i=1;i<=n;++i){
        int k,c;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>c;
            dis[i][c]=(j!=1);
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    if(dis[a][b]==2e4){
        cout<<-1;
        return 0;
    }
    cout<<dis[a][b];
    return 0;
}
