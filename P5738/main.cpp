#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
double s[101];
int main() {
    double ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int sum=0;
        int maxi=0;
        int mini=2e9;
        int c;
        for(int j=1;j<=m;++j){
            cin>>c;
            sum+=c;
            maxi=max(c,maxi);
            mini=min(c,mini);
        }
        sum-=maxi+mini;
        s[i]=sum*1.0/(m-2);
        ans=max(ans,s[i]);
    }
    printf("%.2lf",ans);
    return 0;
}
