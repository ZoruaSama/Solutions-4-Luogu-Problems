#include <iostream>
#include <vector>
using namespace std;
const int maxn=1001;
int in[maxn]={0};
vector<int> nodes[maxn];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        nodes[x].push_back(y);
        in[y]++;
    }
    for(int i=1;i<=n;++i){

    }
    return 0;
}
