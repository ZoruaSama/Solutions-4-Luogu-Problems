#include <iostream>
using namespace std;
const int maxn = 1e5+10;
int par[maxn];
int a,b,p,ans;
bool prime[maxn];
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int main()
{
    cin>>a>>b>>p;
    ans=b-a+1;
    for (int i=a;i<=b;++i){
        par[i]=i;
    }
    for (int i=2;i<=b;++i){
        if (!prime[i]) { // prime[i] is false == i is prime
                if (i>=p){
                    for (int j=i*2;j<=b;j+=i){ //质数的倍数进行合并
                        prime[j]=true; //筛去质数的倍数
                        if (j-i>=a && find(j)!=find(j-i)){
                            //j现在质数的倍数 j-i上一个质数的倍数
                            par[find(j)]=find(j-i);
                            --ans;
                        }
                    }
                }
                else{
                    for (int j=i*2;j<=b;j+=i){
                        //筛去质数的倍数
                        prime[j]=true;
                    }
                }
            }
    }
    cout<<ans;
    return 0;
}