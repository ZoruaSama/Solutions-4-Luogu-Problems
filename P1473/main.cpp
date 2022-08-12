#include <iostream>
using namespace std;
int n;
char re[10]; //每个数字前的符号
int num[10]; //记录每个数字
int pow10[]={1,10,100,1000,10000,100000,1000000};
void dfs(int x,int sum){
    if(x == n){
        if(sum == 0){
            for(int i=1;i<=n;++i){
                if(i!=1){
                    cout<<re[i];
                }
                cout<<i;
            }
            cout<<endl;
        }
        return ;
    }else{
                re[x+1]=' ';
                int w=1,tmp=sum;
                while(re[x+1-w]==' '){
                    w++;
                }
                if(re[x+1-w]=='+'){
                    for(int i=0,xt=x;i<w;++i,xt--) {
                        tmp-=xt*pow10[i];
                    }
                    for(int i=0,xt=x+1;i<=w;++i,xt--) {
                        tmp+=xt*pow10[i];
                    }
                    dfs(x+1,tmp);
                }else if(re[x+1-w]=='-'){
                    for(int i=0,xt=x;i<w;++i,xt--) {
                        tmp+=xt*pow10[i];
                    }
                    for(int i=0,xt=x+1;i<=w;++i,xt--) {
                        tmp-=xt*pow10[i];
                    }
                    dfs(x+1,tmp);
                }
                re[x+1]='+';
                dfs(x+1,sum+x+1);
                re[x+1]='-';
                dfs(x+1,sum-x-1);

            }
}
int main() {
    cin>>n;
    re[1]='+';
    dfs(1,1);
    return 0;
}
/*
        if(re[x]=='+'){
            dfs(x+1,sum-x+10*x+x+1);
        }else if(re[x]=='-'){
            dfs(x+1,sum+x+-10*x-x-1);
        }else{ //re[x]=' ';
 */