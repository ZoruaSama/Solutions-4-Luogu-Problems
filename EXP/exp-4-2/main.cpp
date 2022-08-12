#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct item{
    int id;
    int w;
    int v;
    double vw;
    int g;
}items[100];
bool cmp(item &f,item &s){
    return f.vw>s.vw;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>items[i].w>>items[i].v;
        items[i].id=i;
        items[i].vw=items[i].v*1.0/items[i].w;
    }
    int rest = m;
    double value = 0;
    sort(items+1,items+1+n,cmp);
    int i=1;
    for(;i<=n;i++){
        if(rest < items[i].w){
            break;
        }
        rest -= items[i].w;
        value += items[i].v;
        items[i].g=items[i].w;
    }
    value += items[i].v*rest*1.0/items[i].w;
    items[i].g=rest;
    cout<<value<<endl;
    for(i=1;i<=n;i++){
        cout<<items[i].id<<" "<<items[i].g<<endl;
    }
    return 0;
}
