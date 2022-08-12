#include <iostream>
#include <algorithm>

using namespace std;
int w,n,gift[30000],cnt=0;
int main() {
    cin>>w>>n;
    for(int i=0;i<n;i++){
        cin>>gift[i];
    }
    sort(gift,gift+n);
    int a=0;
    for(int i=n-1;i>=a;i--){
        if(gift[i]+gift[a]<=w){
            cnt++;
            a++;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
