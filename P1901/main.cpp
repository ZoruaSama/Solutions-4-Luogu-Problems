#include <iostream>
#include <algorithm>
#include <stack>
#include <array>
using namespace std;
const int maxn=1000001;
int h[maxn],v[maxn],p[maxn]={0};
stack<int> s;

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>h[i]>>v[i];
        while(!s.empty() && h[s.top()]<h[i]){
            p[i]+=v[s.top()];
            s.pop();
        }
        if(!s.empty()){
            p[s.top()]+=v[i];
        }
        s.push(i);
    }
    cout<<*max_element(p+1,p+1+n);

    return 0;
}
