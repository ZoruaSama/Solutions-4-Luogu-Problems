#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=45;
int n;
int l[maxn];
bool f[1000][1000];
int c;
double ans;
double s(double a,double b,double c){
    if(a<0 || b<0 || c<0) return 0;
    if(a+b<=c || b+c<=a || a+c<=b) return 0;
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",l+i);
        c+=l[i];
    }
    f[0][0]=true;
    for(int i=1;i<=n;++i){
        for(int j=c;j>=0;--j){
            for(int k=c;k>=0;--k){
                if(j>=l[i]) f[j][k]=f[j][k]|f[j-l[i]][k];
                if(k>=l[i]) f[j][k]=f[j][k]|f[j][k-l[i]];
                if(f[j][k]) ans=max(ans,s(j,k,c-j-k));
            }
        }
    }
    if(ans==0){
        printf("-1");
    }else{
        printf("%d",(int)(ans*100));
    }
    return 0;
}
