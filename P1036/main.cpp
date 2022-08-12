#include <iostream>
#include <set>
using namespace std;
int n,k;
int a[20];
int count=0;
bool is_prime(int n){
    for(int i=2;i*i<=n;++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void dfs(int sum,int level){
    if(level==k){
        if(is_prime(sum)){
            count++;
        }
        return ;
    }
    else{
        int c;
        for(int i=0;i<n;++i){
            if(a[i]!=-1){
                c = a[i];
                a[i] = -1;
                dfs(sum+c,level+1);
                a[i] = c;

            }
        }
    }
}

int main() {
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    dfs(0,0);
    for(int i=2;i<=k;++i){
        count/=i;
    }
    cout<<count;
    return 0;
}
