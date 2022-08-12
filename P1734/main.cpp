#include <iostream>
#include <algorithm>
using namespace std;
int ans[1001]={0};
int cal(int a){
    int sum=1;
    if(ans[a]==0){
        for(int i=2;i<a;++i){
            if(a%i == 0){
                sum+=i;
            }
        }
        ans[a]=sum;
        return sum;
    }else{
        return ans[a];
    }

}

int main() {
    int s;
    int f[1000]={0};
    cin>>s;
    for(int i=2;i<=s;++i){
        for(int j=s;j>0;--j){
            if(j>=i){
                f[j]=max(f[j],f[j-i]+cal(i));
            }
        }
    }
    cout<<f[s];
    return 0;
}
