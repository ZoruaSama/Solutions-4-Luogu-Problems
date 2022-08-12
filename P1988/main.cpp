#include <iostream>
#include <queue>
using namespace std;
long long n;
queue<long long> nums; //NOLINT
int main() {
    int cnt=0;
    cin>>n;
    nums.push(1);
    while(!nums.empty()){
        cnt++;
        if(nums.front()<0){
           break;
        }
        if(nums.front()%n==0){
//            cout<<cnt<<endl;
            cout<<nums.front()/n;
//            cout<<endl<<nums.front();
            return 0;
        }
        nums.push(nums.front()*10);
        nums.push(nums.front()*10+1);
        nums.pop();
    }
    cout<<"No Solution";
    return 0;
}
