#include <iostream>
#include <queue>
using namespace std;
const int maxn=30;
const int maxm=610;
struct e{
    int to,next;
}E[maxm];
int tot,head[maxn];
int in[maxn],in_[maxn];
bool vis[maxn];
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
    in[v]++;
}
int n,m;
int f[maxn];
int topo(int k){
    int ans=0;
    int cnt=0;
    queue<int> q;
    for(int i=1;i<=26;++i){
        if(in_[i]==0 && vis[i]){
            q.push(i);
            f[i]=1;
            cnt++;
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            f[v]=max(f[v],f[u]+1);
            ans=max(ans,f[v]);
            in_[v]--;
            if(in_[v]==0){
                cnt++;
                q.push(v);
            }
        }
    }
    if(ans==n){
        cout<<"Sorted sequence determined after "<<k<<" relations: ";
        for(int i=1;i<=n;++i){
            for(int j=1;j<=26;++j){
                if(f[j]==i) {
                    cout<<(char)(j-1+'A');
                    break;
                }
            }
        }
        cout<<".";
        return 1;
    }
    int sum=0;
    for(int i=1;i<=26;++i){
        sum+= vis[i];
    }
    if(cnt!=sum){
        cout<<"Inconsistency found after "<<k<<" relations.";
        return 1;
    }
    return 0;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        string s;
        cin>>s;
        addEdge(s[0]-'A'+1,s[2]-'A'+1);
        vis[s[0]-'A'+1]=true;
        vis[s[2]-'A'+1]=true;
        for(int j=1;j<=26;++j){
            in_[j]=in[j];
        }
        if(topo(i)==1) return 0;
    }
    cout<<"Sorted sequence cannot be determined.";
    return 0;
}
