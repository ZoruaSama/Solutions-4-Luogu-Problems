#include <iostream>
#include <unordered_map>
using namespace std;
const int maxn=5e5+10;
unordered_map<string,int> mp;
struct e{
    int from,to,next;
}E[maxn<<1];
int tot,head[maxn];
int color;
int d[maxn];
int par[maxn];
const string Yes="Possible";
const string No="Impossible";

void addColor(string x){
    if(mp.count(x)==0){
        mp[x]=++color;
    }
}
int Color(string x){
    return mp[x];
}
void addEdge(int u,int v){
    ++tot;
    E[tot].from=u;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
    d[u]++;
}
int find(int x){
    return x==par[x]? x: par[x]=find(par[x]);
}
int main() {
    string a,b;
    while(cin>>a>>b){
        addColor(a),addColor(b);
        addEdge(Color(a),Color(b));
        addEdge(Color(b),Color(a));
    }
    for(int i=1;i<=color;++i){
        par[i]=i;
    }
    for(int i=1;i<=tot;++i){
        int u=find(E[i].from);
        int v=find(E[i].to);
        if(par[u]!=v){
            par[u]=v;
        }
    }
    int cnt=0;
    for(int i=1;i<=color;++i){
        cnt+=(par[i]==i);
    }
    if(cnt>1){
        cout<<No<<endl;
        return 0;
    }
    cnt=0;
    for(int i=1;i<=color;++i){
        cnt+=(d[i]%2==1);
    }
    if(cnt==2||cnt==0)cout<<Yes<<endl;
    else cout<<No<<endl;
    return 0;
}
