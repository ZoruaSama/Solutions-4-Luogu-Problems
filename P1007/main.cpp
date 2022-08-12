#include <iostream>
using namespace std;
int l;
int n;
int x;
int maxn;
int minn;
int main() {
    cin>>l>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        maxn=max(maxn,max(x,l-x+1));
        minn=max(minn,min(x,l-x+1));
    }
    cout<<minn<<' '<<maxn;
    return 0;
}
