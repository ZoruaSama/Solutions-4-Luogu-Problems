#include <iostream>
#include <algorithm>
using namespace std;
struct road{
    int x,y,p;
}roads[90500];
int par[301];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
bool cmp(road a,road b){
    return a.p < b.p;
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=n;++i){
        roads[i].x=0;
        roads[i].y=i;
        cin>>roads[i].p;
    }
    int index=n+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            roads[index].x=i;
            roads[index].y=j;
            cin>>roads[index].p;
            index++;
        }
    }
    sort(roads+1,roads+1+n*n+n,cmp);
    int res=0,cnt=0;
    for(int i=1;i<=n*n+n;++i){
        int nx=find(roads[i].x);
        int ny=find(roads[i].y);
        if(nx!=ny){
            par[nx]=ny;
            res+=roads[i].p;
            cnt++;
            if(cnt==n){
                break;
            }
        }
    }
    cout<<res;
    return 0;
}
