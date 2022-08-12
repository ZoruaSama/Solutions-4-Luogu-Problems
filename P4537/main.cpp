#include <iostream>
using namespace std;
int n;
int a[101];
int fmin[101][101]={0};
int fmax[101][101]={0};
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            if(j==i+1){
                fmin[i][j]=fmax[i][j]=a[i]+a[j];
            }else{
                int minn=2e9;
                int maxn=-1;
                for(int k=i;k<j;++k){
                    minn=min(fmin[i][k]+fmin[k+1][j],minn);
                    maxn=max(fmax[i][k]+fmax[k+1][j],maxn);
                }
                fmin[i][j]=minn;
                fmax[i][j]=maxn;
            }
        }
    }
    cout<<fmin[1][n]<<endl;
    cout<<fmax[1][n]<<endl;
    return 0;
}
