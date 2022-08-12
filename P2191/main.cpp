#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
const int maxn=1001;
char mp[maxn][maxn];
char de;
struct co{
    int x,y;
    bool operator<(const co& cc) const{
        return x<cc.x  || (x==cc.x && y<cc.y);
    }
};
vector<co> coss;
co turn90(co c){
    return co{c.y,n+1-c.x};
}

int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>de;
            if(de=='O'){
                coss.push_back(co{i,j});
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    int num=4;
    do{
        sort(coss.begin(),coss.end());
        for(int i=0;i<coss.size();++i){
            cout<<mp[coss[i].x][coss[i].y];
            coss[i]=turn90(coss[i]);
        }
    }while(--num);
    return 0;
}