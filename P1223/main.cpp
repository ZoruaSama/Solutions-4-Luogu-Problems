#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct p{
    int id;
    int t;
}P[1010];
bool cmp(p &a,p &b){
    return a.t < b.t;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>P[i].t;
        P[i].id=i;
    }
    sort(P+1,P+1+n,cmp);
    double t=0;
    for(int i=1;i<=n;++i){
        cout<<P[i].id<<' ';
        t+=(n-i)*P[i].t;
    }
    printf("\n%.2lf",t/n);
    return 0;
}
