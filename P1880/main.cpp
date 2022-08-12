#include <iostream>
using namespace std;
const int maxn=210;
int a[maxn];
int d[maxn][maxn]; //d[i][j] 表示合并从i开始起j个的得分
int f[maxn][maxn]; //f[i][j]
int q[maxn]={0}; //树状数组维护的前缀和
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=2*n;i+=lowbit(i)){
        q[i]+=v;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=q[i];
    }
    return res;
}
int sum(int x,int y){
    return ask(y)-ask(x-1);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
        add(i,a[i]);
        add(i+n,a[i]);
    }
    for(int j=1;j<=n*2;++j){
        for(int i=1;i+j-1<=n*2;++i){
            if(j==1){
                d[i][j]=0;
                f[i][j]=0;
            }else{
                d[i][j]=2e9;
                f[i][j]=-1;
                for(int k=1;k<j;++k){
                    int sumv=sum(i,i+j-1);
                    d[i][j]=min(d[i][j],d[i][k]+d[i+k][j-k]+sumv);
                    f[i][j]=max(f[i][j],f[i][k]+f[i+k][j-k]+sumv);
                }
            }
        }
    }
    int maxans = -1;
    int minans = 2e9;
    for(int i=1;i<=n;++i){
        minans = min(minans,d[i][n]);
        maxans = max(maxans,f[i][n]);
    }
    cout<<minans<<endl;
    cout<<maxans<<endl;
    return 0;
}
