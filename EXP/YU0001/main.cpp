#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int f[20]={0};
    int a[20]={0};
    int path[20]={0};
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    // 0 10 50 60 70 80 90 100 210
    // 1 2  3  4  5  6  7  8   9
    // 0
    // 200以内
    // f[n]=min(f[i]+(200-a[n]+a[8])*(200-a[n]+a[i]))    i=1..n-1

    for(int i=2;i<=n;++i){
        int minn=2e9;
        for(int j=1;j<=i;++j){
            if(a[i]-a[j]<=200){
                minn = min(minn,f[j] + (200-a[i]+a[j])*(200-a[i]+a[j]));
            }
        }
        f[i]=minn;
    }
    cout<<f[n];
    return 0;
}
