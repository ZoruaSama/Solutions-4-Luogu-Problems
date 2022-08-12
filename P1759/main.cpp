#include <iostream>
using namespace std;
const int maxn=210;
int m,v,n;
int a,b,c;
int f[maxn][maxn];
string s[maxn][maxn];
int main() {
    cin>>m>>v>>n;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
        for(int j=m;j>=a;--j){
            for(int k=v;k>=b;--k){
                if(f[j][k] < f[j-a][k-b]+c){
                    f[j][k] = f[j-a][k-b]+c;
                    s[j][k] = s[j-a][k-b]+to_string(i)+' ';
                }
            }
        }
    }
    cout<<f[m][v]<<endl;
    cout<<s[m][v]<<endl;
    return 0;
}
