#include<iostream>
using namespace std;

int main(){
    long long a[1001]={1,1};
    for(int i=2; i<=1000; i++){
        if(i%2 == 0) a[i] = a[i-1] + a[i/2];
        else a[i] = a[i-1];
    }
    int n;
    cin >> n;
    cout << a[n] << endl;
}