#include <iostream>
#include <algorithm>
#define N 1300
using namespace std;

void add(int* a,int* b,int* c){
    int lena=-1,lenb=-1;
    while(a[++lena]==0);
    while(b[++lenb]==0);
    int lenc = min(lena,lenb);
    for(int i=0;i<=N-1;++i){
        c[i]=0;
    }
    for(int i=N-1;i>=lenc;--i){
        c[i] = c[i]+a[i]+b[i];
        c[i-1] += c[i] / 10;
        c[i]%=10;
    }
}
int main() {
    int f[3][N]={0};
    int n;
    // f[0]=0;
    // f[1]=1;
    // f[2]=2;
    // f[3]=3;
    // f[4]=5;
    // 0 1 2 3 4 5 6 7
    // 0 1 2 3 5 8 13 21 34 55 89 144 233 377
    f[0][N-1]=1;
    f[1][N-1]=2;

    cin>>n;
    if(n==0) {
        cout<<0;
        return 0;
    }
//    for(int n=4;n<=5000;n++) {
        for (int i = 3; i <= n; ++i) {
            add(f[i % 3], f[(i + 1) % 3], f[(i + 2) % 3]);
        }
        int lenc=-1;
        while(f[(n + 2) % 3][++lenc]==0);
        for (int i = lenc; i <= N - 1; ++i) {
            cout <<f[(n + 2) % 3][i];
        }

//    }
    return 0;
}
