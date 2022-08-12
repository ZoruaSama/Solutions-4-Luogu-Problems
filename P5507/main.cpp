#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int s[13];
int a[13][4];
int dis[]={0,3,2,1};
bool vis[16800000];
struct data{
    int s[13]{};
    int step=0;
    int score{};
    int path[30]{};
    bool operator<(const data &other)const {
        return score>other.score;
    }
};

void turn(int x,data &d){
    d.s[x]++;
    if(d.s[x]==4){
        d.s[x]=0;
    }
}

void copy(data &d){
    for(int i=1;i<=12;++i){
        d.s[i]=s[i];
    }
}
void copy_(data &from,data &to){
    to.step=from.step+1;
    for(int i=1;i<=12;++i){
        to.s[i]=from.s[i];
    }
    for(int i=0;i<=from.path[0];++i){
        to.path[i]=from.path[i];
    }
}
int count(data d){
    int res=0;
    for(int j=1;j<=12;++j){
        res = (res<<2)+d.s[j];
    }
    return res;
}
bool check(data &d) {
    return count(d)==0;
}
int rnk(data d){
    int len=0;
    for(int i=1;i<=12;++i){
        len += dis[d.s[i]];
    }
//    return len;
    return len*d.step+len+d.step;
}
priority_queue<data> q;
int main() {
    for(int i=1;i<=12;++i){
        scanf("%d",s+i);s[i]--;
        for(int j=0;j<=3;++j){
            scanf("%d",&a[i][j]);
        }
    }
    data st;
    copy(st);
    q.push(st);
    vis[count(st)]=true;
    while(!q.empty()){
        data from=q.top();q.pop();
        if(from.step > 20){
            continue;
        }
        if(check(from)){
            printf("%d\n", from.step);
            for(int i=1; i <= from.path[0]; ++i){
                printf("%d ", from.path[i]);
            }
            printf("\n");
            break;
        }
        data to;
        for(int i=1;i<=12;++i){
            copy_(from,to);
            turn(a[i][to.s[i]], to);
            turn(i, to);
            int state=count(to);
            if(vis[state]) continue;
            vis[state]=true;
            to.path[++to.path[0]]=i;
            to.score=rnk(to);
            q.push(to);
        }
    }
    return 0;
}
