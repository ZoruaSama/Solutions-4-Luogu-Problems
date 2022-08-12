#include <iostream>
using namespace std;
int lowbit(int x){
    return x&(-x);
}
void div(int x){
    if(x==0){
        return ;
    }else{
        div(x-lowbit(x));
        cout<<lowbit(x)<<' ';
    }
}
int main() {
    int n;
    cin>>n;
    if(n%2==1){
        cout<<-1;
        return 0;
    }
    div(n);
    return 0;
}
