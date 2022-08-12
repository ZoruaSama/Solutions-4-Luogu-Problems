#include <iostream>
#include <queue>
using namespace std;
char mp[101][101];
bool vis[101][101];
queue<int> x;
queue<int> y;
queue<int> t;
queue<int> last;
int main() {
    int n;
    cin>>n;
    int ox,oy;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='A'){
                ox=i;
                oy=j;
            }
        }
    }
    x.push(ox);
    y.push(oy);
    t.push(0);
    last.push(4);
    int xx[]={-1,0,+1,0};
    int yy[]={0,-1,0,+1};
    while(!x.empty()){
        int sx = x.front();
        int sy = y.front();
        int st = t.front();
        int sl = last.front();
        if(mp[sx][sy]=='B'){
            cout<<st;
            break;
        }
        x.pop();y.pop();t.pop();last.pop();
        for(int i=0;i<4;++i){
            int nx = sx+xx[i];
            int ny = sy+yy[i];
            int nt = st+(sl!=4 && sl!=i);
            int nl = i;
            if(nx>=1 && nx<=n && ny>=1 && ny<=n && mp[nx][ny]!='x' && !vis[nx][ny]){
                x.push(nx);
                y.push(ny);
                t.push(nt);
                last.push(nl);
                vis[nx][ny]=true;
            }
        }
    }
    return 0;
}
