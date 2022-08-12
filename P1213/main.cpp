#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=100;
const int goal=262143;
//1	1245
//2	123
//3	2356
//4	147
//5	24568
//6	369
//7	4578
//8	789
//9	5689
int c[10];
bool vis[270000];
struct data{
    int c[10]{};
    int step{};
    int score{};
    int re[maxn]{};
    int t[10]={};
    bool operator<(const data &other)const {
        return (step+1)*(score+1)>(other.step+1)*(other.score+1);
    }
};
int turn(int x,data &d){
    d.c[x]+=1;
    if(d.c[x]==4) d.c[x]=0;
    d.t[x]++;
    if(d.t[x]==4) d.t[0]=1;
}
int move(int x,data &d){
    if(x==1){
        turn(1,d);turn(2,d);turn(4,d);turn(5,d);
    }else if(x==2){
        turn(1,d);turn(2,d);turn(3,d);
    }else if(x==3){
        turn(2,d);turn(3,d);turn(5,d);turn(6,d);
    }else if(x==4){
        turn(1,d);turn(4,d);turn(7,d);
    }else if(x==5){
        turn(2,d);turn(4,d);turn(5,d);turn(6,d);turn(8,d);
    }else if(x==6){
        turn(3,d);turn(6,d);turn(9,d);
    }else if(x==7){
        turn(4,d);turn(5,d);turn(7,d);turn(8,d);
    }else if(x==8){
        turn(7,d);turn(8,d);turn(9,d);
    }else if(x==9){
        turn(5,d);turn(6,d);turn(8,d);turn(9,d);
    }
}
int count(data &d){
    int res=0;
    for(int i=1;i<=9;++i){
        res=(res<<2)+d.c[i];
    }
}
int count2(data &d){
    int res=0;
    for(int i=1;i<=9;++i){
        res+=3-d.c[i];
    }
    return res;
}
int main() {
    for(int i=1;i<=9;++i){
        cin>>c[i];
        c[i]/=3;c[i]--;
        //0--3
        //1--6
        //2--9
        //3--12
    }
    data st;
    st.step=0;
    st.score=0;
    for(int i=1;i<=9;++i){
        st.c[i]=c[i];
    }
    priority_queue<data> q;
    q.push(st);
    vis[count(st)]=true;
    while(!q.empty()){
        data from=q.top();q.pop();
        if(from.step>80) continue;
        if(from.t[0]==1) continue;
        for(int i=1;i<=9;++i){
            data to=from;
            move(i,to);
            if(vis[count(to)]) continue;
            vis[count(to)]=true;
            to.step=from.step+1;
            to.score=count2(to);
            to.re[to.step]=i;
            if(count(to)==goal){
                sort(to.re+1,to.re+1+to.step);
                for(int j=1;j<=to.step;++j){
                    cout<<to.re[j]<<' ';
                }
//                continue;
               return 0;
            }
            q.push(to);
        }
    }
    return 0;
}
