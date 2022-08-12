#include <iostream>
#include <algorithm>
using namespace std;
int maxn=-1;
int main() {
    int n;
    cin>>n;
    int x[701],y[701];
    for(int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
    }
    int sum;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            sum=0;
            int A1=y[j]-y[i];
            int B1=x[i]-x[j];
            for(int k=1;k<=n;++k){
                int A2=y[k]-y[i];
                int B2=x[i]-x[k];
                if(A1*B2==A2*B1) {
                    sum++;
                }
            }
            maxn=max(sum,maxn);
        }

    }
    cout<<maxn;
    return 0;
}
