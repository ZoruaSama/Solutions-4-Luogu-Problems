#include <iostream>
using namespace std;
int n,cnt=0;
unsigned short vis[15]={0};

void dfs(unsigned short a,unsigned short b,unsigned short c,unsigned short line){
    if(b==((1<<n)-1)){
        cnt++;
        return ;
    }else{
        unsigned short  d=((1<<n)-1)&(~(a|b|c|vis[line]));
        while(d){
            unsigned short bit=d&(-d);
            d-=bit;
            dfs((a|bit)<<1,(b|bit),(c|bit)>>1,line+1);
        }
    }
}
int main() {
    cin>>n;
    char ch;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>ch;
            if(ch=='.'){
                vis[i]|=1<<(n-j);
            }
        }
    }
    dfs(0,0,0,1);
    cout<<cnt;
    return 0;
}
