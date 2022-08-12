#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=55;
const char YES[]="^_^";
const char NO[]="T_T";
int t,n;
int zx[maxn];
int hj[maxn];
int rs[maxn][maxn];
struct e{
    int to,next;
}E[maxn*maxn];
int head[maxn];
int tot;
int match[maxn];
int vis[maxn];
int ans;
int num;
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
bool dfs(int u){
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v] || dfs(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tot=0;
        memset(match,0,sizeof(match));
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;++i){
            scanf("%d",zx+i);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",hj+i);
        }
        //是本校的 学生的床能被分配
        //匹配 是本校、没有回家的学生 || 非本校的学生 到 床位上
        //本校   本校 非本校
        //不回家 回家 不回家
        // 1 2认识
        // 1 3认识
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&rs[i][j]);
            }
        }
        // 认识的才可以匹配
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if((i==j && zx[i] && !hj[i]) || (rs[i][j] && zx[j])){
//                    cout<<i<<"->"<<j<<endl;
                    addEdge(i,j);
                }
            }
        }
        num=0;
        for(int i=1;i<=n;++i){
            if(((zx[i] && !hj[i]) || (!zx[i]))) num++;
        }
        ans=0;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
            if(((zx[i] && !hj[i]) || (!zx[i])) && dfs(i)) ans++;
        }
//        cout<<ans<<' '<<num<<endl;
        printf("%s\n",ans==num ? YES:NO);
    }
    return 0;
}