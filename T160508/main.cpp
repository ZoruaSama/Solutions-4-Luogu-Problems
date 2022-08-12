#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int x;
int main() {
    cin>>x;
    double res=4.0;
    if(x>=90){
        res=4.0;
    }else if(x>=60){
        res -= (90-x)*0.1;
    }else{
        x = (int)(sqrt(x)*10);
        if(x>=90){
            res=4.0;
        }else if(x>=60) {
            res -= (90 - x) * 0.1;
        }else{
            res = 0;
        }
    }
    printf("%.1lf",res);
    return 0;
}
