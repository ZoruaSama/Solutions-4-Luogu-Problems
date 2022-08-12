#include <iostream>
using namespace std;
int main() {
    int n,m,cnt=1,s=0;
    cin>>n>>m;
    while(n--){
        int a;
        cin>>a;
        if(s+a<=m){
            s+=a;
        }else{
            cnt+=1;
            s=a;
        }
    }
    cout<<cnt;
    return 0;
}
