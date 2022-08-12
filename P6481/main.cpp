#include <iostream>
using namespace std;
const int maxx=5e5;

int a[maxx]={0};
int f[maxx]={0};
int n,h;
int lowbit(int x){
    return x&-x;
}
void add(int x,int v){
    for(int i=x;i<=h;i+=lowbit(i)){
        a[i]+=v;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res+=a[i];
    }
    return res;
}
int main() {
    cin>>n>>h;
    for(int i=1;i<=n;++i){
        int c;
        cin>>c;
        if(i%2==1){
            add(c+1,-1);
            add(1,1);
        }else{
            add(h+1,-1);
            add(h-c+1,1);
        }
    }
    int res=2e9;
    for(int i=1;i<=h;++i){
        f[i]=ask(i);
        res=min(res,f[i]);
    }
    int cnt=0;
    for(int i=1;i<=h;++i){
        if(f[i]==res){
            cnt++;
        }
    }
    cout<<res<<' '<<cnt;
    return 0;
}
