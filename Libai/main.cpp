#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
int n=0,m;
char mp[6][6];
bool vis[6][6][6]={false};
int xx[]={-1,0,+1,0};
int yy[]={0,+1,0,-1};
int res=2e9;
vector<string> re;
stringstream re_min;

void dfs(int x,int y,int s,int t,int sk,int skt,int ox,int oy){
    if(t>res){
        return ;
    }
    if(s==n){
        res = min(res,t);
        re_min.clear();
        re_min.str("");
        for(int i=0;i<re.size();++i){
            re_min<<re[i]<<endl;
        }
        return ;
    }
    if(skt>0) {
        skt--;
        if(sk==4 && skt>0) dfs(x,y,s,t+1,sk,skt,ox,oy);
    }
    if(skt==0){
        if(sk==2 || sk==3){
            skt=3;
        }
        sk=1;
    }

    for(int i=0;i<4;++i){
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<m && !vis[nx][ny][s] && mp[nx][ny]!='X'){
            stringstream temp;
            temp<<"李白移动到了("<<nx<<","<<ny<<")";
            vis[nx][ny][s]=true;
            re.push_back(temp.str());
            dfs(nx,ny,s,t+1,sk,skt,ox,oy);
            re.pop_back();
            vis[nx][ny][s]=false;
        }
    }
    if((sk==1 && skt==0 )|| sk==2 ){
        for(int i=0;i<4;++i){
            int nx=x+2*xx[i];
            int ny=y+2*yy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<m && !vis[nx][ny][s] && mp[nx][ny]!='X'){
                vis[nx][ny][s]=true;
                stringstream temp;
                temp<<"李白将进酒"<<sk<<"到了("<<nx<<","<<ny<<")";
                re.push_back(temp.str());
                if(sk==1){
                    dfs(nx,ny,s,t+1,sk+1,5,x,y);
                }
                else {
                    dfs(nx,ny,s,t+1,sk+1,5,ox,oy);
                }
                re.pop_back();
                vis[nx][ny][s]=false;
            }
        }
    }else if(sk==3){
        stringstream temp;
        temp<<"李白将进酒"<<sk<<"到了("<<ox<<","<<oy<<")";
        re.push_back(temp.str());
        dfs(ox,oy,s,t+1,4,3,ox,oy);
        re.pop_back();
    }
    if(mp[x][y]=='Y'){
        stringstream temp;
        temp<<"李白击败了野怪"<<"("<<x<<","<<y<<")";
        re.push_back(temp.str());
        mp[x][y]='O';
        dfs(x,y,s+1,t+1,sk,skt,ox,oy);
        mp[x][y]='Y';
        re.pop_back();
    }



}
int main() {
    cin>>m;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<m;++i) {
        for (int j = 0; j < m; ++j) {
            if(mp[i][j]=='Y'){
                n++;
            }
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='L'){
                cout<<"Start"<<endl;
                dfs(i,j,0,0,1,0,0,0);
                break;
            }
        }
    }
    if(res!=2e9) cout<<res<<endl;
    else cout<<-1;
    cout<<re_min.str();
    /*
5
OLXOY
OXXOO
OOXXO
OYXOY
XXXOO

7
OLXOYOO
OXXOOOO
OOXXOOO
OYXOOYO
XXXXOOO
OOYXXXX
XXXXXXX

6
OOYXXY
XXOOXO
OOLOOO
XXOOOY
XXXOOO
OOYXOO
     * */
    return 0;
}
