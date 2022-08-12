#include <iostream>
#include <algorithm>
#include <vector>
//O(n^2)
//O(nlogn)
using namespace std;
const int maxn = 1e5;
int a[maxn],b[maxn];
int f[maxn];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[a[i]];
    }
    //贪心+二分
    int len=1;
    vector<int> tail(n+1,2e9);
    //tail[x] 表示长度为x的最长子序列的末尾的数字
    for(int i=1;i<=n;++i){
        int x = lower_bound(tail.begin()+1,tail.end(),b[i])-tail.begin();
        tail[x]=b[i];
        len=max(len,x);
    }
    cout<<len;
//    for(int i=1;i<=n;++i){
//        cout<<b[i]<<' ';
//    }
    return 0;
}
