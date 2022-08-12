#include <iostream>
#include <cstdio>
using namespace std;
double s,L,kpl,r;
double sp[52]={0},sr[52]={0};
int n;
double res=2e9;
void dfs(double ns,double cost,int next,double LL){
    if(cost>=res){
        return ;
    }
    if(ns>=s){
        res=min(res,cost);
        return ;
    }else{
        LL-=(sp[next]-ns)/kpl;
        if(sp[next+1]-sp[next] >= LL*kpl){
            //必须要加油
            dfs(sp[next],cost+sr[next]*(L-LL)+20,next+1,L);
        }else{
            if(LL<0.5*L){
                //可加可不加
                dfs(sp[next],cost+sr[next]*(L-LL)+20,next+1,L);
                dfs(sp[next],cost,next+1,LL);
            }else{
                dfs(sp[next],cost,next+1,LL);
            }
        }
    }
}
int main() {
    cin>>s;
    cin>>L>>kpl>>r>>n;
    for(int i=1;i<=n;++i){
        cin>>sp[i]>>sr[i];
    }
    sp[n+1]=s;
    sr[n+1]=0;
    dfs(0,r,0,L);
    printf("%.1lf",res);
    return 0;
}
