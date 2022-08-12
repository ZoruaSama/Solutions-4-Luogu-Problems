#include <iostream>
#include <stack>
using namespace std;
int n,c;
int a[10001];
stack<int> s;
int isfull(){
    return s.size() >= c;
}
int main() {
    cin>>n>>c;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    a[n+1]=2e9+1;
    for(int i=1;i<=n+1;++i){
        while(!s.empty() && s.top() < a[i]){
            cout<<s.top()<<' ';
            s.pop();
        }
        if(isfull()){
            cout<<s.top()<<' ';
            s.pop();
        }
        s.push(a[i]);
    }
    return 0;
}
