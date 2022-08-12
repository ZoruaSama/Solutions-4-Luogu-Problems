#include <iostream>
#include <algorithm>
#include <math.h>
bool r[10][10]={0};
bool c[10][10]={0};
bool z[10][10]={0};
int mp[10][10]={0};
int score=-1;
using namespace std;
struct node{
    int num,cnt;
}ss[10];
void dfs(int x,int y){
    int sx=x;
    x=ss[sx].num;
    if(sx==9){
        int sum=0;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                sum+=mp[i][j]*min(10-abs(i-4),10-abs(j-4));
            }
        }
        score = max(sum,score);
        return ;
    }
    if(y==9){
        dfs(sx+1,0);
        return;
    }
    if(mp[x][y]){
        dfs(sx,y+1);
    }else{
        for(int i=1;i<=9;++i){
            if(!r[x][i] && !c[y][i] && !z[x/3*3+y/3][i]){
                r[x][i] = true;
                c[y][i] =true;
                z[x/3*3+y/3][i]=true;
                mp[x][y]=i;
                dfs(sx,y+1);
                mp[x][y]=0;
                r[x][i] = false;
                c[y][i] = false;
                z[x/3*3+y/3][i]=false;
            }
        }
    }

}
bool cmp(node a,node b){
    return a.cnt > b.cnt;
}
int main() {
    for(int i=0;i<9;++i){
        ss[i].num=i;
        ss[i].cnt=0;
        for(int j=0;j<9;++j){
            cin>>mp[i][j];
            if(mp[i][j]){
                ss[i].cnt++;
                r[i][mp[i][j]]= true;
                c[j][mp[i][j]]= true;
                z[i/3*3+j/3][mp[i][j]] = true;
            }
        }
    }
    sort(ss,ss+9,cmp);
    dfs(0,0);
    cout<<score;
    return 0;
}
