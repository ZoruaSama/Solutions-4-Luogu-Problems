#include <iostream>
#include <map>
using namespace std;
map<string, string> par;
string find(string x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
int main() {
    int n,m,k;
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s;
        par[s]=s;
    }
    for(int i=1;i<=m;++i){
         string s1,s2;
         cin>>s1>>s2;
         par[find(s1)]=find(s2);
    }
    cin>>k;
    for(int i=1;i<=k;++i){
        string s1,s2;
        cin>>s1>>s2;
        if(find(s1)==find(s2)){
            cout<<"Yes."<<endl;
        }else{
            cout<<"No."<<endl;
        }
    }
    return 0;
}
