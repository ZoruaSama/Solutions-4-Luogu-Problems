#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+1;
int n;
struct cow{
    int t,d;
}cows[maxn];
bool cmp(cow &a,cow &b){
    return a.t*1.0/a.d < b.t*1.0/b.d;
}
int main() {
    long long ans=0;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>cows[i].t>>cows[i].d;
        sum+=cows[i].d;
    }
    sort(cows+1,cows+1+n,cmp);
    for(int i=1;i<=n;++i){
        sum-=cows[i].d;
        ans+=2*cows[i].t*sum;
    }
    cout<<ans;
    return 0;
}
