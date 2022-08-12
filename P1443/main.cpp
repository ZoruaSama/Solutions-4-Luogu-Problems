#include <iostream>
#include <queue>
#include <cstdio>
#include <iomanip>
int mp[410][410]={0};
using namespace std;
int main(){
    int n,m,x,y;
    int xx[] = {1,2,1,2,-1,-2,-1,-2};
    int yy[] = {2,1,-2,-1,-2,-1,2,1};
    queue<int> xm;
    queue<int> ym;
    cin>>n>>m>>x>>y;
    xm.push(x);
    ym.push(y);
    mp[x][y]=1;
    while(!xm.empty()){
        for(int i=0;i<8;++i){
            int tx = xm.front() + xx[i];
            int ty = ym.front() + yy[i];
            if(tx>0 && ty>0 && tx<=n && ty<=m && mp[tx][ty]==0){
                xm.push(tx);
                ym.push(ty);
                mp[tx][ty]=mp[xm.front()][ym.front()] + 1;
            }
        }
        xm.pop();
        ym.pop();
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<left<<setw(5)<<mp[i][j]-1;
        }
        if(i!= n)
            cout<<endl;
    }
    return 0;
}