#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5e3+10;
int n;
struct s{
    int l,w;
    bool operator<(const s &other)const{
        return l>other.l;
    }
}S[maxn];
int vis[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>S[i].l>>S[i].w;
    }
    sort(S+1,S+1+n);
    int cnt=0;
    int bj=0;
    while(bj<n){
        int last=2e9;
        for(int i=1;i<=n;++i){
            if(!vis[i] && S[i].w<=last){
                vis[i]=1;
                last=S[i].w;
                bj++;
            }
        }
        if(last!=2e9) cnt++;
    }
    cout<<cnt;
    return 0;
}
