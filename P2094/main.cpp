#include <iostream>
#include <queue>

using namespace std;
int n,k;
int w;
priority_queue<int,vector<int>,less<int> > q;
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>w;
        q.push(w);
    }
    while(q.size()!=1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push((a+b)/k);
    }
    cout<<q.top();
    return 0;
}
