#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int x,y;
}nodes[100001];
int f[100001]={0};
bool cmp(node &a,node &b){
    return a.x < b.x || (a.x==b.x && a.y<b.y);
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;++i){
        cin>>nodes[i].x>>nodes[i].y;
    }
    sort(nodes+1,nodes+1+k,cmp);
    int cnt=0;
    node *last;
    last = &nodes[1];
    f[0]=last->x;
    f[nodes[1].y]=nodes[1].x;
    for(int i=2;i<=k;++i){
        if(nodes[i].x!=last->x){
            f[0]=last->x;
        }
        if(nodes[i].y==last->y+1 && nodes[i].x==last->x) cnt++;
        if(nodes[i].x==f[0]+1 && f[nodes[i].y]==f[0]) cnt++;
        last=&nodes[i];
        f[nodes[i].y]=nodes[i].x;
    }
    cout<<cnt;
    return 0;
}
