#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn=100001;
vector<int> edge[maxn];
queue<int> quq; //NOLINT
bool vis[maxn]={false};
int n,m;
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

void dfs(int x){
    write(x);
    putchar(' ');
    for(int i=0;i<edge[x].size();++i){
        if(!vis[edge[x][i]]){
            vis[edge[x][i]]=true;
            dfs(edge[x][i]);
        }
  }
}
void bfs(){
    quq.push(1);
    while(!quq.empty()){
        write(quq.front());
        putchar(' ');
        for(int i=0;i<edge[quq.front()].size();++i){
            if(!vis[edge[quq.front()][i]]){
                vis[edge[quq.front()][i]]=true;
                quq.push(edge[quq.front()][i]);
            }
        }
        quq.pop();
    }
}
int main() {
    n=read();
    m=read();
    for(int i=0;i<m;++i){
        int x,y;
        x=read();
        y=read();
        edge[x].push_back(y);
    }
    for(int i=1;i<=n;++i){
        sort(edge[i].begin(),edge[i].end());
    }
    vis[1]=true;
    dfs(1);
    cout<<endl;
    for(int i=2;i<=n;++i) vis[i]=false;
    bfs();
    cout<<endl;
    return 0;
}
