#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int a[3000001];
int main() {
    int n;
    stack<int> s;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        if(s.empty() || a[s.top()]>a[i]){
            s.push(i);
        }else{
            while(s.size()>0 && a[s.top()]<=a[i]){
                s.pop();
            }
        }
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
