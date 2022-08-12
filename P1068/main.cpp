#include <iostream>
#include <algorithm>

using namespace std;
struct node{
    int k;
    int s;
}p[5001];
bool cmp(node f,node s){
    if(f.s > s.s){
        return true;
    }else return f.s == s.s && f.k < s.k;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>p[i].k>>p[i].s;
    }
    sort(p,p+n,cmp);
    int cnt=0;
    for(cnt=0;p[cnt].s >= p[(int)(m*1.5)-1].s;++cnt);
    cout<<p[(int)(m*1.5)-1].s<<' '<<cnt<<endl;
    for(int i=0;p[i].s >= p[(int)(m*1.5)-1].s;++i){
        cout<<p[i].k<<' '<<p[i].s<<endl;
    }
    return 0;
}
