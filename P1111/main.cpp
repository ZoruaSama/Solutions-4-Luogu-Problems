#include <iostream>
#include <algorithm>
using namespace std;
struct road{
    int x;
    int y;
    int t;
}roads[100001];
int par[1001];
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
bool cmp(road x,road y){
    return x.t < y.t;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        roads[i].x = read();
        roads[i].y = read();
        roads[i].t = read();
    }
    sort(roads+1,roads+1+m,cmp);
    int cnt=0;
    int time;
    for(time=1;time<=m;++time){
        if(find(roads[time].x) != find(roads[time].y)){
            par[find(roads[time].x)] = find(roads[time].y);
            cnt++;
            if(cnt==n-1){
                break;
            }
        }
    }
    if(cnt==n-1){
        write(roads[time].t);
    }else{
        write(-1);
    }
    return 0;
}
