#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
double x[15];
double y[15];
double dp[65000][17]={0};
double res=2e9;
bool vis[15]={false};
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(double xx,double yy,int m,double s,int bi){
    if(s>res){
        return ;
    }
    if(m==n){
        res=min(res,s);
        return ;
    }else{
        for(int i=0;i<n;++i){
            if(!vis[i]){
                int t = bi+(1<<i);          //NOLINT
                double w = s+dist(xx,yy,x[i],y[i]);
                if(dp[t][i]!=0 && dp[t][i]<w){
                    continue;
                }
                vis[i]=true;
                dp[t][i] = w;
                dfs(x[i],y[i],m+1,dp[t][i],t);
                vis[i]=false;
            }
        }
    }
}
int main() {
    cin>>n;
    int bi=0;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
    }
    dfs(0,0,0,0,bi);
    printf("%.2lf",res);
    return 0;
}
