#include <iostream>
using namespace std;
int cost[]={6,2,5,5,4,5,6,3,7,6};
int cal_cost(int num){
    if(num<10){
        return cost[num%10];
    }else{
        return cal_cost(num/10) + cost[num%10];
    }
}
int main() {
    int n;
    int sum=0;
    cin >> n;
    n-=4;
    for(int i=0;i<888;++i){
        for(int j=0;j<888;++j){
            if(cal_cost(i)+cal_cost(j)+cal_cost(i+j)==n){
                sum+=1;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
