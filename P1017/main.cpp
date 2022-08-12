#include <iostream>
using namespace std;
char baseNum[]="0123456789ABCDEFGHIJ";
void dg(int n,int R){
    if(n==0){
        return;
    }else{
        int a=n%R;
        if(a>=0){
            dg(n/R,R);
            cout<<baseNum[a];
        }else{
            dg(n/R+1,R);
            cout<<baseNum[a-R];
        }
    }
}
int main() {
    int n,R;
    cin>>n>>R;
    cout<<n<<'=';
    dg(n,R);
    cout<<"(base"<<R<<')';
    return 0;
}
