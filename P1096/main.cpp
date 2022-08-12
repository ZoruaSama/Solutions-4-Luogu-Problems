#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans[100]={0};
    int jw=0;
    for(int i=1;i<=n;i++){
        jw=0;
        for(int j=0;j<100;j++){
            ans[j] = ans[j] * 2 + jw;
            jw=ans[j]/10;
            ans[j]%=10;
        }
        ans[0] += 2;
        for(int j=0;j<100;j++){
            ans[j]+=jw;
            if(ans[j]>=10){
                jw=ans[j]/10;
                ans[j]%=10;
            }else{
                break;
            }
        }
    }
    int j;
    for(j=99;j>=0;j--){
        if(ans[j]!=0) break;
    }
    for(;j>=0;j--){
        cout<<ans[j];
    }
    return 0;
}

//int hanoi(int n){
//    if(n==1){
//        return 2;
//    }else
//        return 2*hanoi(n-1)+2;
//}