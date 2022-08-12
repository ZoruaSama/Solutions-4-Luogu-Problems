#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n;
bool s[10001];
double b[10001],g[10001];
int nb,ng;
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        nb=ng=0;
        for(int i=1;i<=n;++i){
            cin>>s[i];
        }
        for(int i=1;i<=n;++i){
            if(s[i]){
                cin>>b[++nb];
            }else{
                cin>>g[++ng];
            }
        }
        sort(b+1,b+1+nb);
        sort(g+1,g+1+ng);
        for(int i=1;i<=ng;++i){
            cout<<g[i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=nb;++i){
            cout<<b[i]<<' ';
        }
    }
    return 0;
}
