#include <iostream>
#include <cmath>
using namespace std;
int a[250];
int f[250][250]={0}; //f[i][j]表示合并第i个起j个后最大的数
int q[250];//前缀和数组
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        q[i]+=v;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=q[i];
    }
    return log2(res);
}
int main() {
    cin>>n;
    //倍增DP
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int j=1;j<=n;++j){
        for(int i=1;i+j-1<=n;++i){
            if(j==1){
                f[i][j]=a[i];
            }else{
                for(int k=0;k<j;++k){
                    if(f[i][k]==f[i+k][j-k]){

                    }
                }
            }
        }
    }
    return 0;
}
