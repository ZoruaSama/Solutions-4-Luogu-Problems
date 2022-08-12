#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
stack<int> nums;
int main() {
    char c='0';
    int num=0;
    while(c!='@'){
        cin>>c;
        if(isdigit(c)){
            num*=10;
            num+=(c-48);
        }
        else if(c=='.'){
            nums.push(num);
            num=0;
        }
        else if(c=='+'){
            int a=nums.top();
            nums.pop();
            int b=nums.top();
            nums.pop();
            nums.push(a+b);
        }
        else if(c=='-'){
            int a=nums.top();
            nums.pop();
            int b=nums.top();
            nums.pop();
            nums.push(b-a);
        }
        else if(c=='*'){
            int a=nums.top();
            nums.pop();
            int b=nums.top();
            nums.pop();
            nums.push(a*b);
        }
        else if(c=='/'){
            int a=nums.top();
            nums.pop();
            int b=nums.top();
            nums.pop();
            nums.push(b/a);
        }
    }

    cout<<nums.top();
    return 0;
}
