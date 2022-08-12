#include <iostream>

int lowbit(int x){
    return x&(-x); //NOLINT
}
long long a[500001]={0};
long long c[500001];
int n,m;
using namespace std;
void add(int x,long long v){
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=v;
    }
}
long long ask(int x){
    long long res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res+=c[i];
    }
    return res;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;++i){
        int cm,x,y;
        long long k;
        cin>>cm;
        if(cm==1){
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }else{
            cin>>x;
            cout<<ask(x)<<endl;
        }
    }
    return 0;
}
