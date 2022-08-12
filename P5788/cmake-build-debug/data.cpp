#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int main(){
    srand((int)time(0));
    const int n = 3000001;
    int num = rand()%n+1; 
    const int maxn=1e9+1;
    for(int i=1;i<=num;++i){
        cout<<rand()%maxn+1<<' ';
    }
    return 0;
}