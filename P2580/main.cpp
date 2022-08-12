#include <iostream>
#include <vector>
using namespace std;
struct node{
    char u;
    int v[26];
    bool w;
    bool r;
};
vector<node> nodes;
int main() {
    int n,m;
    cin>>n;
    string s;
    int cnt=0;
    nodes.push_back(node{'*',{0},false,false});
    for(int i=1;i<=n;++i){
        cin>>s;
        int now=0;
        for(int j=0;j<s.length();++j){
            if(nodes[now].v[s[j]-'a']==0){
                nodes.push_back(node{s[j],{0},false,false});
                nodes[now].v[s[j]-'a']=++cnt;
            }
            now=nodes[now].v[s[j]-'a'];
        }
        nodes[now].w=true;
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>s;
        int now=0;
        bool flag=false;
        for(int j=0;j<s.length();++j){
            if(nodes[now].v[s[j]-'a']!=0){
                now=nodes[now].v[s[j]-'a'];
            }else{
                flag=true;
                break;
            }
        }
        if(!flag && nodes[now].w){
            if(nodes[now].r){
                cout<<"REPEAT"<<endl;
            }else{
                cout<<"OK"<<endl;
                nodes[now].r=true;
            }
        }else{
            cout<<"WRONG"<<endl;
        }

    }
    return 0;
}
