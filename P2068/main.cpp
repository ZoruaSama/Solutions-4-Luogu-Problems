#include <iostream>
int n,x;
long long c[100001]={0};
int lowbit(unsigned int m){
    return m&(-m); //NOLINT
}
void add(int m,long long v){
    for(int i=m;i<=n;i+=lowbit(i)){
        c[i]+=v;
    }
}
long long ask(long long m){
    long long res = 0;
    for(int i=m;i>=1;i-=lowbit(i)){
        res+=c[i];
    }
    return res;
}
using namespace std;
int main() {
    cin>>n>>x;
    char cm;
    int a;
    long long b;
    while(x--){
        cin>>cm>>a>>b;
        if(cm=='x') {
            add(a,b);
        }else if(cm=='y'){
            cout<<ask(b)-ask(a-1)<<endl;
        }
    }
    return 0;
}
