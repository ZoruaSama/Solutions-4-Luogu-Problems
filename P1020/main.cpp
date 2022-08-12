#include <iostream>
#include <algorithm>
using namespace std;


const int maxn=1e5+10;
int maxx=0;
int f[50010]={0};
int g[50010]={0};

int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    while(x<=maxx){
        f[x]=max(f[x],v);
        x+=lowbit(x);
    }
}
void add_(int x,int v){
    while(x>0){
        g[x]=max(g[x],v);
        x-=lowbit(x);
    }
}
int ask(int x){
    int res=0;
    while(x>0){
        res = max(res,f[x]);
        x-=lowbit(x);
    }
    return res;
}
int ask_(int x){
    int res=0;
    while(x<=maxx){
        res = max(res,g[x]);
        x+=lowbit(x);
    }
    return res;
}
int a[maxn]={0};
int main() {
    int n=0;
    int ans1=0;
    int ans2=0;
    while(cin>>a[n]){
        maxx=max(maxx,a[n]);
        n++;
    }

    for(int i=0;i<n;++i){
        int x = ask(a[i])+1;
        ans1=max(ans1,x);
        add(a[i]+1,x);
    }

    for(int i=0;i<n;++i){
        int y = ask_(a[i])+1;
        ans2 = max(ans2,y);
        add_(a[i],y);
    }
    cout<<ans2<<endl;
    cout<<ans1<<endl;
    return 0;
}
