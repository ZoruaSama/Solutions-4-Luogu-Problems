#include <iostream>
#include <queue>
using namespace std;
bool vis[100001]={false};
int t,x,y;
queue<int> q;
queue<int> ts;
int main() {
    cin>>t;
    while(t--){
        cin>>x>>y;
        q.push(x);
        vis[x]=true;
        ts.push(0);
        while(!q.empty()){
           int now=q.front();
           if(now==y){
               cout<<ts.front()<<endl;
               break;
           }
           if(now+1<=100000 && !vis[now+1] ){
               vis[now+1]=true;
               q.push(now+1);
               ts.push(ts.front()+1);
           }
           if(now-1>=1 && !vis[now-1]){
               vis[now-1]=true;
               q.push(now-1);
               ts.push(ts.front()+1);
           }
           if(now*2>=1 && now*2<=100000 && !vis[now*2]){
                vis[now*2]=true;
                q.push(now*2);
                ts.push(ts.front()+1);
           }
           q.pop();
           ts.pop();
        }
        while(!q.empty()){
            q.pop();
            ts.pop();
        }
        for(int i=0;i<100001;++i){
            vis[i]=false;
        }
    }

    return 0;
}
