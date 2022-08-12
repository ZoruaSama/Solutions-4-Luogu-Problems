#include <iostream>
using namespace std;
int n;
int x[501],y[501];
int e[510][510],tot;
int dis(int a,int b){
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
int ans;
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            e[i][j] = e[j][i] = dis(i,j);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int k=j+1;k<=n;++k){
                for(int l=k+1;l<=n;++l){
                    if(e[i][j]==e[j][k] && e[j][k]==e[k][l] && e[k][l]==e[l][i]){
                        cout<<i<<j<<k<<l<<endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
