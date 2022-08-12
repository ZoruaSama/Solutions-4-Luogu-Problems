#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int maxn=54; //字母的总数量
struct e{
    int to,next;
    int s;
}E[maxn*maxn];
int tot,head[maxn];
int d[maxn]; //记录点的度
bool vis[maxn][maxn]; //记录边是否被访问过
int idx; //记录输出答案的序列
string ans[maxn*maxn]; //记录输出的答案
string s[maxn*maxn]; //记录所有字符串
int num;//记录点的总数
int dfs_num;//在dfs中记录点的总数
bool point[maxn]; //是否有该点
void addEdge(int u,int v,int w){
    ++tot;
    point[u]=true;
    point[v]=true;
    E[tot].to=v;
    E[tot].next=head[u];
    E[tot].s=w;
    head[u]=tot;
    d[u]++;
}
int char2int(char x){
    if('A'<=x && x<='Z'){
        return x-'A'+1;
    }else{
        return x-'a'+27;
    }
}
char int2char(int x){
    if(1<=x && x<=26){
        return 'A'+x-1;
    }else{
        return 'a'+x-27;
    }
}
void dfs(int u){
    if(point[u]){
        point[u]=false;
        dfs_num++;
    }
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(!vis[u][v]){
            vis[u][v]=vis[v][u]=true;
            dfs(v);
            ++idx;
            ans[idx]=s[E[i].s];
        }
    }
}
void prt(){
    for(int i=idx;i>=1;--i){
        cout<<ans[i][0];
    }
    cout<<ans[1][1];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        string t;
        cin>>t;
        s[i]=t;
        s[i+n]=t;
        swap(s[i+n][0],s[i+n][1]);
    }
    sort(s+1,s+1+n*2);
    int st=char2int(s[1][0]);
    for(int i=n*2;i>=1;--i){
        int u=char2int(s[i][0]);
        int v=char2int(s[i][1]);
        addEdge(u,v,i);
    }
    int cnt=0;
    for(int i=1;i<=52;++i){
        if(d[i]%2==1){
            cnt++;
        }
        if(point[i]){
            num++;
        }
    }
    if(cnt==2){
        st=2e9;
        for(int i=1;i<=52;++i){
            if(d[i]%2==1){
                st=min(st,i);
            }
        }
    }
    if(cnt!=0 && cnt!=2){
        cout<<"No Solution"<<endl;
        return 0;
    }
    dfs(st);
    if(dfs_num < num){
        cout<<"No Solution"<<endl;
        return 0; //不连通
    }
    prt();
    return 0;
}
