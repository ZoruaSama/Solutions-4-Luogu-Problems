#include <iostream>
#include <queue>
#include <functional>
using namespace std;
const int maxn=10001;
priority_queue<int,vector<int>, greater<int> > q;

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        q.push(a);
    }
    int res=0;
    for(int i=1;i<n;++i){
        int x = q.top();q.pop();
        int y = q.top();q.pop();
        q.push(x+y);
        res+=x+y;
    }
    cout<<res;
    return 0;
}
