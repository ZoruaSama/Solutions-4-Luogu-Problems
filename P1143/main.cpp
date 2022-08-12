#include <iostream>
using namespace std;
char sz[]="0123456789ABCDEF";
void dg(int x,int n){
    if(x==0) return;
    dg(x/n,n);
    cout<<sz[x%n];
}
int main() {
    int n,m;
    string d;
    int s=0;
    cin>>n>>d>>m;
    for(int i=0;i<d.length();++i){
        s*=n;
        if(isdigit(d[i])){
            s+=d[i]-'0';
        }else if(isalpha(d[i])){
            s+=d[i]-'A'+10;
        }
    }
    dg(s,m);
    return 0;
}
