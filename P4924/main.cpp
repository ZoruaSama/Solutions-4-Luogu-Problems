#include <iostream>
using namespace std;
int n,m;
int mp[501][501];
void turn(int x,int y,int r,int z){
    int temp=-1;
    for(int i=0;i<2*r;++i){
        temp = mp[x-r+i+1][y-r];
        mp[x-r+i+1][y-r]=mp[x-r+i][y-r];
    }
    mp[x+r][y-r]=temp;
    for(int i=0;i<2*r;++i){
        temp = mp[x+r][y-r+i+1];
        mp[x+r][y-r+i+1]=mp[x+r][y-r+i];
    }
    mp[x+r][y+r]=temp;
    for(int i=0;i<2*r;++i){
        temp = mp[x+r-(i+1)][y+r];
        mp[x+r-(i+1)][y+r]=mp[x+r-i][y+r];
    }
    mp[x-r][y+r]=temp;


    mp[x-r][y-r]=temp;
}
int main() {
    int x,y,r,z;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            mp[i][j]=(i-1)*n+j;
        }
    }
    for(int i=1;i<=m;++i){
        cin>>x>>y>>r>>z;
        turn(x,y,r,z);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<mp[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
