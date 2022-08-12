#include <iostream>
using namespace std;
int n;
int h;
int main() {
    cin>>n;
    int b=0,sum=0;
    for(int i=1;i<=n;++i){
        cin>>h;
        if(h>b) sum+=h-b;
        b=h;
    }
    cout<<sum;
    return 0;
}
//把序列分成(a1,..ai)(ai+1,...aj)......(ak,...an)多个非递减序列。
//然后所有段中最大值的和减去除第一段外的段的最小值，化简一下，就出来了