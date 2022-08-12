#include <iostream>
#include <vector>
using namespace std;
struct node{
    bool isWord;
    int c[26];
};
vector<node> tree;
int main() {
    int n;
    cin>>n;
    int now;
    int index=1;
    int cnt;
    int ans=0;
    tree.push_back(node{false});
    for(int i=1;i<=n;++i){
        now=0;
        cnt=0;
        string s;
        cin>>s;
        for(int j=0;j<s.length();++j){
            if(tree[now].c[s[j]-'a']==0){
                tree.push_back(node{false});
                tree[now].c[s[j]-'a']=index;
                index++;
            }
            now=tree[now].c[s[j]-'a'];
            if(j==s.length()-1){
                tree[now].isWord = true;
            }
            if(tree[now].isWord){
                cnt++;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
