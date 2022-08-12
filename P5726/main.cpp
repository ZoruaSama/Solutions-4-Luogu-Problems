#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n,sum=0,min,max;
    cin>>n;
    cin>>min;
    max=min;
    sum=min;
    for(int i=1;i<n;i++){
        int d;
        cin>>d;
        if(d>max){max=d;}
        if(d<min){min=d;}
        sum+=d;
    }
    printf("%.2f",(sum-max-min)*1.0/(n-2));
    return 0;
}
