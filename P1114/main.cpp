#include <iostream>
using namespace std;
int sum[100001]={0};
int main() {
    int n,d;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>d;
        d*=2;
        if(i==1){
            sum[i]=d;
        }else{
            sum[i]=sum[i-1]+d;
        }
    }
    int ans=0;

    for(int i=1;i<=n;++i){
        for(int j=n;j>i;--j){
            if(j-i<ans){
                break ;
            }
            if(j-i+1 == sum[j]-sum[i-1]){
                ans = max(ans,j-i+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
