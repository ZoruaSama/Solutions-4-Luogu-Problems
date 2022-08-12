#include <iostream>
#include <algorithm>
using namespace std;
int n;
string s;
int res=2e9;
bool addop[40]={false};
void dfs(int index,int t){
    int sum=0;
    int tmp=0;
    for(int i=0;i<=s.length();++i){
        if(addop[i] || i==s.length()){
            sum+=tmp;
            tmp=0;
        }
        if(i<s.length()){
            tmp*=10;
            tmp+=s[i]-'0';
        }
    }
    if(t>res){
        return ;
    }
    if(index==s.length()+1){
        return ;
    }
    if(sum==n){
        res=min(res,t);
        return ;
    }else{
        addop[index]=true;
        dfs(index+1,t+1);
        addop[index]=false;
        dfs(index+1,t);
    }
}
int main() {
    cin>>s>>n;
    int sum=0;
    for(int i=0;i<s.length();++i){
        sum+=s[i]-'0';
    }
    if(sum>n){
        cout<<-1;
        return 0;
    }
    dfs(1,0);
    if(res!=2e9){
        cout<<res;
    }else{
        cout<<-1;
    }
    return 0;
}
