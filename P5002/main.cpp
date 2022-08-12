#include <iostream>
#include <vector>
#include<cstdio>
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
using namespace std;
vector<int> node[10001];
long long ans[10001]={0};
const int modn = 1e9+7;
long long memo[10001]={0}; //memo[i]表示节点i下的节点数量
long long dfs(int x,int fa){
    long long cnt=1;
    if(memo[x]!=0) return memo[x];
    for(int i=0;i<node[x].size();++i){
        if(node[x][i]==fa){
            node[x][i]=-1;
            continue;
        }
        cnt+=dfs(node[x][i],x);
    }
    return memo[x]=cnt;
}
int main() {
    int n,r,m;
    cin>>n>>r>>m;
    for(int i=1;i<n;++i){
        int a,b;
        a=read();
        b=read();
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(r,r);
    for(int i=1;i<=m;++i){
        int p;
        p=read();
        if(ans[p]!=0){
            cout<<ans[p]-1<<endl;
            continue;
        }
        long long int res = 0;

        for(int i=0;i<node[p].size();++i){
            if(node[p][i]==-1) continue;
            res += memo[node[p][i]]*memo[node[p][i]];
            res %= modn;
        }
        ans[p]=memo[p]*memo[p]-res+1;
        cout<<ans[p]-1<<endl;
    }
    return 0;
}
