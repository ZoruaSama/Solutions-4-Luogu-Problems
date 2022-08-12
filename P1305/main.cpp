#include <iostream>
#include <map>
using namespace std;
map<char,char> tleft;     //NOLINT
map<char,char> tright;   //NOLINT
bool vis[27]={0};
bool root[27]={0};
void dfs(char x){
    if(x=='*'){
        return ;
    }
    cout<<x;
    dfs(tleft[x]);
    dfs(tright[x]);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        char s,l,r;
        cin>>s>>l>>r;
        tleft[s]=l;
        tright[s]=r;
        vis[s-'a'+1]=true;
        vis[l-'a'+1]=true;
        vis[r-'a'+1]=true;
        root[l-'a'+1]=true;
        root[r-'a'+1]=true;
    }
    for(int i=1;i<=26;i++){
        if(!root[i] && vis[i]){
            dfs((char)(i+'a'-1));
        }
    }
    return 0;
}
