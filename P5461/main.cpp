#include <iostream>
using namespace std;
int a[1025][1025]={0};
void sm(int n,int ax,int ay,int bx,int by){
    if(n==0){
        return ;
    }else{
//        cout<<ax<<' '<<ay<<' '<<ax-1+bx/2<<' '<<ay-1+by/2<<endl;
        for(int i=ax;i<=ax-1+bx/2;++i){      //NOLINT
            for(int j=ay;j<=ay-1+by/2;++j){  //NOLINT
                a[i][j]=1;
            }
        }
        sm(n-1,(ax+ax+bx)/2,ay,bx/2,by/2);      //NOLINT
        sm(n-1,ax,(ay+ay+by)/2,bx/2,by/2);      //NOLINT
        sm(n-1,(ax+ax+bx)/2,(ay+ay+by)/2,bx/2,by/2); //NOLINT
    }
}
int main() {

    int n;
    cin>>n;
    sm(n,1,1,1<<n,1<<n);//NOLINT
    for(int i=1;i<=(1<<n);++i){//NOLINT
        for(int j=1;j<=(1<<n);++j){ //NOLINT
            cout<<1-a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
