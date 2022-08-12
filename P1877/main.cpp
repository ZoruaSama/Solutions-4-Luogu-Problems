#include <iostream>
using namespace std;
int c[51];
int n,beginLevel,maxLevel;
bool f[51][1001];
int main() {
    cin>>n>>beginLevel>>maxLevel;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    f[0][beginLevel]=true;
    for(int i=1;i<=n;++i){
        for(int j=maxLevel;j>=0;--j){
            if(f[i-1][j] && j+c[i]<=maxLevel) f[i][j+c[i]]=true;
            if(f[i-1][j] && j-c[i]>=0) f[i][j-c[i]]=true;
        }
    }
    for(int i=maxLevel;i>=0;--i){
        if(f[n][i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}