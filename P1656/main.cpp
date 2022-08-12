#include <iostream>
#include <algorithm>
using namespace std;
struct road{
    int a;
    int b;
}roads[5001];
int par[151];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
bool cmp(road a,road b){
    return a.a < b.a || (a.a==b.a && a.b < b.b);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        roads[i].a=a;
        roads[i].b=b;

    }
    sort(roads+1,roads+1+m,cmp);
    for(int k=1;k<=m;++k){
        for(int i=1;i<=n;++i){
            par[i]=i;
        }
        int cnt=0;
        for(int i=1;i<=m;++i){
            if(i==k) continue;
            if(find(roads[i].a)!=find(roads[i].b)){
                par[find(roads[i].a)]=find(roads[i].b);
                cnt++;
                if(cnt==n-1){
                    break;
                }
            }
        }
        if(cnt<n-1){
            cout<<roads[k].a<<' '<<roads[k].b<<endl;
        }
    }
    return 0;
}
