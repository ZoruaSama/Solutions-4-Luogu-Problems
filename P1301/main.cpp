#include <iostream>
#include <queue>

using namespace std;
int n,m;
const int maxn=1001;
int mp[maxn][maxn];
bool vis[maxn][maxn][8]={false};
queue<int> x,ox;
queue<int> y,oy;
queue<int> stp;
queue<int> from;
int main() {
    cin>>m>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
        }
    }
    x.push(1);
    y.push(1);
    stp.push(0);
    from.push(8);
    ox.push(1);
    oy.push(1);
    while(!x.empty()){
        if(x.front()==n && y.front()==m){
//            cout<<stp.front()<<' '<<x.front()<<' '<<y.front()<<' '<<ox.front()<<' '<<oy.front()<<endl;
            cout<<stp.front();
            return 0;
        }
        int xx[]={-1,0,+1,0,+1,-1,+1,-1};
        int yy[]={0,+1,0,-1,-1,-1,+1,+1};
        for(int i=0;i<8;++i){
            if(i==from.front()) {
                continue ;
            }
            int nx = x.front() + xx[i]*mp[x.front()][y.front()];
            int ny = y.front() + yy[i]*mp[x.front()][y.front()];
            if(nx>=1 && ny>=1 && nx<=n && ny<=m && !vis[x.front()][y.front()][i]){
                vis[x.front()][y.front()][i]=true;
                x.push(nx);
                y.push(ny);
                stp.push(stp.front()+1);
                from.push(i);
//                ox.push(x.front());
//                oy.push(y.front());
            }
        }
//        cout<<stp.front()<<' '<<x.front()<<' '<<y.front()<<' '<<ox.front()<<' '<<oy.front()<<' '<<mp[x.front()][y.front()]<<endl;
        x.pop();
        y.pop();
        stp.pop();
        from.pop();
//        ox.pop();
//        oy.pop();
    }
    cout<<"NEVER";
    return 0;
}
