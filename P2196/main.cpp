#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[21];
int mp[21][21]={0};
int p[21]={0};
int f[21]={0};
int maxn=0,maxi;
void prt(int x){
    if(!x) return ;
    prt(p[x]);
    cout<<x<<" ";
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        f[i] = a[i];
        for(int j=1;j<=i-1;++j){
            if(mp[j][i]){
                if(a[i] + f[j] > f[i]){
                    f[i] = a[i] + f[j];
                    p[i]= j;
                }
            }
        }
    }

    for(int i=1;i<=n;++i){
        if(maxn<f[i]){
            maxn=f[i];
            maxi=i;
        }
    }
    prt(maxi);
    cout<<endl<<maxn;
    return 0;
}