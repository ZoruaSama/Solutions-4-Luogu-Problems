#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n*n;++i){
        printf("%02d",i);
        if(i%n==0){
            cout<<endl;
        }
    }
    cout<<endl;
    int a=1;
    for(int i=1;i<=n;++i){
        int s=n-i;
        for(int j=0;j<s;++j){
            cout<<"  ";
        }
        for(int j=0;j<i;++j){
            printf("%02d",a);
            a++;
        }
        cout<<endl;
    }
    return 0;
}
