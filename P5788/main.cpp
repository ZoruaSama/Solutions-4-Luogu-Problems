#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
stack<int> s;
int a[100001];
int pos[100001]={0};
int main() {
    int n,d;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&d);
        a[i]=d;
        if(s.empty() || a[s.top()]>=a[i]){
            s.push(i);
        }else{
            while(!s.empty() && a[s.top()]<a[i]){
                pos[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",pos[i]);
    }
    return 0;
}
