#include <iostream>
#include <stack>
using namespace std;
stack<long long> num;
stack<char> ope;
int main() {
    string s;
    cin>>s;
    s=s+'$';
    long long temp=0;
    for(int x=0;x<s.length();x++){
        char i=s[x];
        if(isdigit(i)){
            temp*=10;
            temp+=i-'0';
        }else{
            num.push(temp%10000);
            temp=0;
            while(!ope.empty() && ope.top()=='*'){
                long long a=num.top();
                num.pop();
                long long b=num.top();
                num.pop();
                ope.pop();
                num.push((a*b)%10000);
            }
            ope.push(i);
        }
    }
    long long sum=0;
    while(!num.empty()){
        sum+=num.top();
        sum%=10000;
        num.pop();
    }
    cout<<sum%10000;
    return 0;
}
