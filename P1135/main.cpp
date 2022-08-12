#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,a,b,k[201];
    bool vis[201];
    for(int i=0;i<201;++i){
        vis[i]=false;
    }
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i){
        cin>>k[i];
    }
    queue <int> e;
    queue <int> cs;
    e.push(a);
    cs.push(0);
    vis[a]=true;
    while(!e.empty()){
        if(e.front()==b){
            cout << cs.front();
            return 0;
        }
        int up = e.front() + k[e.front()];
        if(up>=1 && up<= n && !vis[up]){
            e.push(up);
            cs.push(cs.front()+1);
            vis[up] = true;
        }
        int down = e.front() - k[e.front()];
        if(down>=1 && down<= n && !vis[down]){
            e.push(down);
            cs.push(cs.front()+1);
            vis[down] = true;
        }
        e.pop();
        cs.pop();
    }
    cout<<-1;
    return 0;
}