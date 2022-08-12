#include <iostream>
#define ll long long
using namespace std;
int n;
struct t{
    bool flag;
    int k[26];
}T[2510];
struct e{
    int to,next,u;
}E[2510];
int tot;
int tot_;
int head[2510];
ll f[2510][2];//树形DP 对于节点i j是否选择0/1
void addEdge(int u,int v){
    E[++tot_].to=v;
    E[tot_].next=head[u];
    E[tot_].u=u;
    head[u]=tot_;
}
void rebuild(int x,int fa){
    if(T[x].flag){
        addEdge(fa,x);
        fa=x;
    }
    for(int i=0;i<26;++i){
        if(T[x].k[i]!=0){
            rebuild(T[x].k[i],fa);
        }
    }
}
void insert(string &s){
    int len=s.length();
    int now=0;
    for(int i=0;i<len;++i){
        if(T[now].k[s[i]-'a']==0){
            T[now].k[s[i]-'a'] = ++tot;
        }
        now=T[now].k[s[i]-'a'];
        if(i==len-1){
            T[now].flag=true;
        }
    }
}
void dp(int x){
    f[x][0]=f[x][1]=1;
    for(int i=head[x];i;i=E[i].next){
        int y = E[i].to;
        dp(y);
        f[x][0]*=f[y][0]+f[y][1];
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        insert(s);
    }
    rebuild(0,0);
    dp(0);
    cout<<f[0][0];
    return 0;
}
