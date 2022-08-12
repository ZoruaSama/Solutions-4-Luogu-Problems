#include <iostream>
#include <cstdio>
using namespace std;
int n;
double b;
struct node{
    int x,y;
    int operator*(node &other){
        return (x*other.y-other.x*y);
    }
}nodes[110];
int dabs(int x){
    if(x>=0){
        return x;
    }else{
        return -x;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&nodes[i].x,&nodes[i].y);
    }
    nodes[n+1]=nodes[1];
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=nodes[i]*nodes[i+1];
    }
    printf("%d",dabs(ans/2));
    return 0;
}