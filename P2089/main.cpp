#include <iostream>
#include <sstream>
using namespace std;
int a[10]={1,1,1,1,1,1,1,1,1,1};
int cnt=0;
stringstream ss;
void dfs(int n,int s){
    if(n==0){
        cnt++;
        for(int i=0;i<10;++i){
            ss << a[i] << ' ';
        }
        ss<<endl;
        return;
    }
    else if(s>=10){
        return ;
    }
    else{
        for(int i=1;i<=3;++i){
            if(n>=i-1){
                a[s]=i;
                dfs(n-(i-1),s+1);
                a[s]=1;
            }
        }
    }

}
int main() {
    int n;
    cin>>n;
    if(n<10 || n>30){
        cout<<0;
        return 0;
    }
    else{
        dfs(n-10,0);
    }
    cout<<cnt<<endl;

    cout<<ss.str();
    return 0;
}