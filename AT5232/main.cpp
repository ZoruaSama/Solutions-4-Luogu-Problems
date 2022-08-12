#include <stdio.h>
const int maxn=1e5+10;
struct e{
    int to,next;
}E[maxn<<1];
int head[maxn],tot;//双向边，所以数组要开大一倍
int h[maxn],n,m,ans;//s为符合条件的点的总数
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(a,b);
        addEdge(b,a);
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=head[i];j;j=E[j].next)
            if(h[i]<=h[E[j].to]) flag=false;
        if(flag) ++ans;
    }
    printf("%d\n",ans);//输出
    return 0;
}