#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e3+10;
struct e{
    int to,next;
    bool vis;
    int w;
}E[maxn*maxn];
int tot,head[maxn];
string ans[maxn];
string s[maxn];
int d[27];
void addEdge(int u,int v,int w){
    tot++;
    E[tot].to=v;
    E[tot].next=head[u];
    E[tot].w=w;
    head[u]=tot;
    d[u]++;
    d[v]--;
}
int n;
int st;
int idx;
void dfs(int x){
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(!E[i].vis){
            E[i].vis=true;
            dfs(y); //先dfs再记录
            idx++;
            ans[idx]=s[E[i].w];
        }
    }
}

void prt(){
    for(int i=idx;i>1;--i){
        cout<<ans[i]<<'.';
    }
    cout<<ans[1];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    st=s[1][0]-'a'+1;
    for(int i=n;i>=1;--i){
        addEdge(s[i][0]-'a'+1,s[i][s[i].length()-1]-'a'+1,i);
    }
    for(int i=1;i<=26;++i){
        if(d[i]==1){
            st=i;
            break;
        }
    }
    dfs(st);
    for(int i=1;i<=tot;++i){
        if(!E[i].vis){
            cout<<"***";
            return 0;
        }
    }
    prt();
    return 0;
}
