#include <iostream>
using namespace std;
const int maxx=110;
int a[maxx]={0};
int f[maxx]={0};
int g[maxx]={0};


int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]-=129;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;j++) {
            if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);
        }
    }
    for(int i=n;i>0;--i){
        for(int j=n+1;j>i;--j) {
            if(a[i]>a[j]) g[i]=max(g[i],g[j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,f[i]+g[i]-1);
    }
    cout<<n-ans;
    return 0;
}


//int lowbit(int x){
//    return x&-x;
//}
//void add(int x,int v){
//    for(int i=x;i<=maxx;i+=lowbit(i)){
//        f[i]=max(f[i],v);
//    }
//}
//int ask(int x){
//    int res=0;
//    for(int i=x;i>0;i-=lowbit(i)){
//        res=max(res,f[i]);
//    }
//    return res;
//}
//void add_(int x,int v){
//    for(int i=x;i>0;i-=lowbit(i)){
//        g[i]=max(g[i],v);
//    }
//}
//int ask_(int x){
//    int res=0;
//    for(int i=x;i<=maxx;i+=lowbit(i)){
//        res=max(res,g[i]);
//    }
//    return res;
//}

/*
    for(int i=1;i<=n;++i){
        int x=ask(a[i])+1;
        int y=ask_(a[i])+1;
        add(a[i]+1,x);
        add_(a[i]+1,y);
        cout<<x<<' '<<y<<endl;
    }
 */