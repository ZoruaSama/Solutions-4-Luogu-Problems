#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define ull unsigned long long
ull h[80003];
ull p[80003];
stack<int> s;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>h[i];
    }
    h[n+1]=2e9;
    for(int i=1;i<=n+1;++i){
        while(!s.empty() && h[s.top()]<=h[i]){
            p[s.top()]=i-s.top()-1;
            s.pop();
        }
        s.push(i);
    }
    ull sum=0;
    for(int i=1;i<=n;++i){
        sum+=p[i];
    }
    cout<<sum;
    return 0;
}
