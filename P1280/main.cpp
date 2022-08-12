#include <iostream>
#include <vector>
using namespace std;
const int maxn=1e4+10;
const int maxk=1e4+10;
int n,k;
struct t{
    int p,t;
}T[maxn];
int f[maxk];
vector<int> tsk[maxn];
//最大空暇时间 最小工作时间
int main() {
    cin>>n>>k;
    for(int i=1;i<=k;++i){
        cin>>T[i].p>>T[i].t;
        tsk[T[i].p].push_back(i);
    }
    for(int i=n;i>=0;--i){
        if(tsk[i].empty()) f[i]=f[i+1]+1;
        else{
            for(int j=0;j<tsk[i].size();++j){
                f[i]=max(f[i],f[i+T[tsk[i][j]].t]);
            }
        }
    }
    cout<<f[1];
    return 0;
}
