#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;
int n;
const int maxn=2e5+10;
vector<int> br[maxn];
struct node{
    ll x,y;
    bool operator<(const node &b)const
    {
        if(x==b.x)
            return y<b.y;
        else
            return x<b.x;
    }
    ll step;
    string s;
};
map<node,int> br_id;
map<node,int> vis;

ll sx,sy,ex,ey;
ll dx[]={-1,0,+1,0};
ll dy[]={0,-1,0,+1};
const ll maxb=1e18;
int main() {
    cin>>n;
    string s(n,'0');
    int bh=0;
    for(int i=1;i<=n;++i){
        int x,y;
        cin>>x>>y;
        node a = node{x,y};
        if(br_id.count(a)==0){
            br_id[a]=bh++;
        }
        br[br_id[a]].push_back(i);
    }
    cin>>sx>>sy>>ex>>ey;
    vis[node{sx,sy}]=1;
    queue<node> q;
    q.push(node{sx,sy,0,s});
    while(!q.empty()){
        node now = q.front();q.pop();
        if(now.x==ex && now.y==ey){
            cout<<now.step<<endl;
            cout<<now.s;
            break;
        }else{
            ll x = now.x;
            ll y = now.y;
            ll step = now.step;
            string ns = now.s;
            int b;
            for(int i=0;i<4;++i){
                ll nx=x+dx[i];
                ll ny=y+dy[i];
                node nn=node{nx,ny};
                int id;
                if(nx>=0 && ny>=0 && nx<=maxb && ny <=maxb && ((nx&ny)==0) && vis.count(nn)==0){
                    node a = node{nx,ny};
                    if(br_id.count(a)==1){
                        id = br_id[a];
                        for(int j=0;j<br[id].size();++j){
                            ns[br[id][j]-1]='1';
                        }
                    }
                    vis[nn]=1;
//                    if(b==1) cout<<x<<' '<<y<<' '<<nx<<' '<<ny<<' '<<step+1<<' '<<ns<<endl;
                    q.push(node{nx,ny,step+1,ns});
                    if(br_id.count(a)==1){
                        id = br_id[a];
                        for(int j=0;j<br[id].size();++j){
                            ns[br[id][j]-1]='0';
                        }
                    }
                }
            }
            }
        }
    return 0;
}
