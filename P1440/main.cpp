#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n,m;
    const int maxnn=2000001;
    int a[maxnn];
    int f[maxnn][maxnn];
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    f[1][1]=0;
    for(int i=2;i<=n;++i){
        f[i][1]=a[i-1];   //往前看一个的话 永远都是前一个
    }
    for(int i=2;i<=m;++i){
        f[1][i]=0;        // 往前看m个的话 第一个往前看是0
    }
    for(int j=2;j<=m;++j){
        for(int i=2;i<=n;++i){
            if(j>=i){
                f[i][j]=f[i][i-1];
            }else{
                f[i][j]=min(f[i-1][j-1],f[i][1]);  //往前看j个 就是比较 i-1的往前看j-1个和i的往前看1个
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d\n",f[i][m]);
    }
    return 0;
}


//if(i-j<0){ //前面不足m个
//                f[i][j]=min(a[i-1],f[i-1][j-1]);
//            }else if(a[i-j]!= f[i-1][j]){ //第一个数不是最小值
//                f[i][j]=min(a[i-1],f[i-1][j-1]);
//            }else{ //第一个数是最小值
//                f[i][j]=min(f[i-1][j-1],a[i-1]);
//            }