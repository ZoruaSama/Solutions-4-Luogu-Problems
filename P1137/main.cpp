#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
const int maxn=100001;
vector<int> nodes[maxn];
struct edge{
    int u,v;
}edge[2*maxn];

int f[maxn]={0};
int in[maxn]={0};
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        nodes[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=0;i<nodes[now].size();++i){
            int nnode = nodes[now][i];
            f[nnode] = max(f[nnode],f[now]+1);
            in[nnode]--;
            if(in[nnode]==0){
                q.push(nnode);
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<f[i]+1<<endl;
    }
    return 0;
}
