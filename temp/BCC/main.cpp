#include <iostream>
std::string bcc(std::string x){
    int res=0;
    std::string ans="0x";
    int len=x.length();
    std::string hex="0123456789ABCDEF";
    for(int i=0;i<len;i+=2){
        int a = x[i]-'0';
        int b = x[i+1]-'0';
        int c = (a<<4) + b;
        res^=c;
    }
    ans+=hex[res/16];
    ans+=hex[res%16];
    return ans;
}

int main() {
    std::cout<<bcc("1234567890");
    return 0;
}
