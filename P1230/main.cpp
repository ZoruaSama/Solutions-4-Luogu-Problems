#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int m,n;
struct a{
    int t,w;
    bool operator<(const a &aa)const{
        return w<aa.w;
    }
}as[501];
bool cmp(a &x1,a &x2){
    return x1.t>x2.t;
}

priority_queue<a> q;
int main() {
    cin>>m>>n;
    for(int i=1;i<=n;++i){
        cin>>as[i].t;
    }
    for(int i=1;i<=n;++i){
        cin>>as[i].w;
        m-=as[i].w;
    }
    sort(as+1,as+1+n,cmp);
    int id = 1;
    for(int i=n;i>=1;--i){
        while(id<=n && as[id].t>=i){
            q.push(as[id]);
            id++;
        }
        if(!q.empty()){
            m+=q.top().w;
            q.pop();
        }
    }
    cout<<m;
    return 0;
}
