#include <iostream>
using namespace std;
int main() {
    long long ans(0);
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();
    for(int i=0;i<l1-1;++i){
        for(int j=1;j<l2;++j){
            if(s1[i]==s2[j] && s1[i+1]==s2[j-1]){
                ++ans;
            }
        }
    }
    cout<<(1<<ans);
    return 0;
}
