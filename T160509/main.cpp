#include <iostream>
#include <algorithm>
using namespace std;
int n;

const int maxn=500001;

struct s{
    int t;
    int k;
    int tk;
    int id;
}ss[maxn];
bool cmp(s s1,s s2){
    return s1.tk > s2.tk || (s1.tk==s2.tk && s1.t>s2.t)||(s1.tk==s2.tk && s1.t==s2.t && s1.id<s2.id);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>ss[i].t>>ss[i].k;
        ss[i].tk=ss[i].t*ss[i].k;
        ss[i].id=i;
    }
    sort(ss+1,ss+1+n,cmp);
    for(int i=1;i<=n;++i){
        cout<<ss[i].id<<' ';
    }
    return 0;
}
