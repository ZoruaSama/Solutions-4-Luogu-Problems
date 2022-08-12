#include <iostream>
long long a[500001]={0};
long long c[500001]={0};
int lowbit(unsigned int x){
    return x&(-x); //NOLINT
}
using namespace std;
int n,m;
void fix(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i))
        c[i]+=v;
}
long long ask(int x){
    long long res=0;
    for(int i=x;i>=1;i-=lowbit(i))
        res+=c[i];
    return res;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        fix(i,a[i]);
    }
    for(int i=1;i<=m;++i){
        int c,x,y;
        cin>>c>>x>>y;
        if(c==1){
            fix(x,y);
        }else if(c==2){
            cout<<ask(y)-ask(x-1)<<endl;
        }
    }
    return 0;
}
