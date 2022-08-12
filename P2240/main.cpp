#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct item{
    int m,v;
    double vpm;
}items[101];
bool cmp(item item1,item item2){
    return item1.vpm > item2.vpm;
}
int main() {
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;++i){
        cin>>items[i].m>>items[i].v;
        items[i].vpm=items[i].v*1.0/items[i].m;
    }
    sort(items+1,items+1+n,cmp);
    double res = 0;
    for(int i=1;i<=n;++i){
        if(t>=items[i].m){
            t-=items[i].m;
            res+=items[i].v;
        }else{
            res+=t*items[i].vpm;
            break;
        }
    }
    printf("%.2lf",res);
    return 0;
}
