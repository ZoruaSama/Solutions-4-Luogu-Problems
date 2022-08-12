#include <iostream>
#include <vector>
using namespace std;
struct trie{
    int abc[26]{};
    trie(){
        for(int i=0;i<26;++i){
            abc[i]=0;
        }
    }
};
vector<trie> t;
int main() {
    string s;
    int newi=0;
    t.emplace_back();
    while(cin>>s){
        int cur=0;
        if(s=="0") break;
        for(int i=0;i<s.length();++i){
            if(t[cur].abc[s[i]-'A']==0){
                t[cur].abc[s[i]-'A']=++newi;
                t.emplace_back();
            }
            cur=t[cur].abc[s[i]-'A'];
        }
    }
    cout<<t.size();
    return 0;
}
