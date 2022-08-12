#include <iostream>

using namespace std;
int books[300001];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>books[i];
    }
    int flag=n;
    int cnt=0;
    for(int i=n;i>=1;--i){
        if(books[i]!=flag){
            cnt++;
        }else{
            flag--;
        }
    }
    cout<<cnt;
    return 0;
}
