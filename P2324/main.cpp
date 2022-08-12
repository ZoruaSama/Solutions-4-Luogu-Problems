#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct data{
    char mp[6][6]{};
    int ox{},oy{};
    int step=0;
    int score{};
    bool operator<(const data &other)const{
//        return step+score>other.step + other.score;
        return (step+1)*(score+1)>(other.step+1)*(other.score+1);
    }
};
int dx[]={-2, -2, -1, -1, 1, 1, 2, 2};
int dy[]={-1 , 1, -2,  2,-2, 2,-1, 1};
int t;
int vis[16800000]; //最终状态: 16501792  1<<25的状态压缩?
const int goal=16501792;
const char goal_mp[6][6]={'-','-','-','-','-','-',
                          '-','1','1','1','1','1',
                          '-','0','1','1','1','1',
                          '-','0','0','*','1','1',
                          '-','0','0','0','1','1',
                          '-','0','0','0','0','1',};
int count(data &d){
    int res=0;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(d.mp[i][j]=='*') continue;
            res=(res<<1) + (d.mp[i][j]-'0');
        }
    }
    return res;
}
int count2(data &d){
    int res=0;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            res += d.mp[i][j]!=goal_mp[i][j];
        }
    }
    return res;
}
priority_queue<data> q;

int main() {
    cin>>t;
    while(t--){
        data s;
        for(int k=0;k<16800000;++k){
            vis[k]=0;
        }
        for(int i=1;i<=5;++i){
            for(int j=1;j<=5;++j){
                cin>>s.mp[i][j];
                if(s.mp[i][j]=='*'){
                    s.ox=i;s.oy=j;
                }
            }
        }
        vis[count(s)]|=1<<((s.ox-1)*5+s.oy);
        q.push(s);
        bool flag=false;
        while(!q.empty()){
            data from = q.top();q.pop();
            if(count(from)==goal && from.ox==3 && from.oy==3){
                cout<<from.step<<endl;
                flag=true;
                break;
            }
            if(from.step + from.score>18 || from.step>=15) continue;
            for(int i=0;i<8;++i){
                data to=from;
                int nx=to.ox+dx[i];
                int ny=to.oy+dy[i];
                if(nx>=1 && nx<=5 && ny>=1 && ny<=5){
                    swap(to.mp[nx][ny],to.mp[to.ox][to.oy]);
                    to.ox=nx;
                    to.oy=ny;
                    to.step++;
                    to.score=count2(to);
                    if((vis[count(to)] & (1<<((to.ox-1)*5+to.oy))) !=0) continue;
                    vis[count(to)]|=(1<<((to.ox-1)*5+to.oy));
                    q.push(to);
                }
            }
        }
        while(!q.empty()){
            q.pop();
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
