#include <iostream>
using namespace std;
int main() {
    bool num[10]={false};
    for(int i=123;i<333;++i){
        int a=2*i;
        int b=3*i;
        for(int j=0;j<10;++j){
            num[j]=false;
        }
        num[i/100]=true;
        num[a/100]=true;
        num[b/100]=true;
        num[i/10%10]=true;
        num[a/10%10]=true;
        num[b/10%10]=true;
        num[i%10]=true;
        num[a%10]=true;
        num[b%10]=true;
        int sum=0;
        for(int j=1;j<10;++j){
            sum+=num[j];
        }
        if(sum==9){
            cout<<i<<' '<<a<<' '<<b<<' '<<endl;
        }


    }
    return 0;
}
