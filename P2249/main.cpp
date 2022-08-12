#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
//int search(int k,int i,int j){
//    int m=(i+j)/2;
//    if(i==j){
//        if(k!=a[m])
//        return -1;
//    }
//    if(k==a[m]){
//        return m+1;
//    }else if(k>a[m]){
//        return search(k,m+1,j);
//    }else{
//        return search(k,i,m-1);
//    }
//
//}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];

    }
    for(int i=0;i<m;++i){
        int k;
        cin>>k;
        int ans = lower_bound(a,a+n,k)-a;
        if(k!=a[ans]) cout<<-1<<' ';//没有，输出-1
        else cout<<ans+1<<' ';//有，输出ans
    }
    return 0;
}
