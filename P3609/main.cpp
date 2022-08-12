#include <iostream>
using namespace std;
const int maxn=1e5+10;
int n,k;
char a[maxn];
int f[4][maxn][21];
int ss2i(char x){
    if(x=='P'){
        return 1;
    }else if(x=='H'){
        return 2;
    }
    return 3;
}
int max3(int &x,int &y,int &z){
    return max(x,max(y,z));
}
int isWin(char x,char y){
    if(x=='P' && y=='H' ||
       x=='H' && y=='S' ||
       x=='S' && y=='P'){
        return 1;
    }else{
        return 0;
    }
}
char change(char x,int id){
    char P_[] = "SH";
    char H_[] = "PS";
    char S_[] = "HP";
    if(x=='P'){
        return P_[id];
    }else if(x=='H'){
        return H_[id];
    }else if(x=='S'){
        return S_[id];
    }
}
int dfs(char ss,int n_,int k_){
    if(k_>k || n_>n){
        return 0;
    }
    if(f[ss2i(ss)][n_][k_]!=0){
        return f[ss2i(ss)][n_][k_];
    }
    else{
        int res = 0;
        int f1 = dfs(ss,n_+1,k_);
        int f2 = dfs(change(ss,0),n_+1,k_+1);
        int f3 = dfs(change(ss,1),n_+1,k_+1);
        if(isWin(ss,a[n_])){
            res = 1;
        }
        return f[ss2i(ss)][n_][k_] = res+max3(f1,f2,f3);
    }
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int f1 = dfs('P',1,0);
    int f2 = dfs('H',1,0);
    int f3 = dfs('S',1,0);
    cout<<max3(f1,f2,f3);
    return 0;
}