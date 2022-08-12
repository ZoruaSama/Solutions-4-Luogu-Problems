#include <iostream>
#include <cstdio>
using namespace std;
int a[100001];
int n,m;
int lowbit(int x){
    return x&-x;
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        a[i]=(a[i]+1)%2;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res+=a[i];
    }
    return res%2;
}
int main() {
    scanf("%d%d",&n,&m);
    int c,l,r;
    for(int i=1;i<=m;++i){
        scanf("%d",&c);
        if(c==1){
            scanf("%d%d",&l,&r);
            add(r+1,1);
            add(l,1);
        }else{
            scanf("%d",&l);
            printf("%d\n",ask(l));
        }
    }
    return 0;
}
