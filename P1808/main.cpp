#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int count=1;
    string s[10000];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
    }
    sort(s,s+n);
    for(int i=1;i<n;++i){
        if(s[i]!=s[i-1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}
