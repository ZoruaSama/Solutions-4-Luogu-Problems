#include <iostream>
using namespace std;
int main() {
    int ans[10]={0};
    string s;
    cin>>s;
    string a(s.length(),'0');
    while(a != s){
        int k=1; //进位
        for(int i=a.length()-1;i>=0;--i){
            int m = a[i] - 48 + k;
            a[i] = m % 10 + 48;
            k = m / 10;
            if(k==0){
                break;
            }
        }
        int sts;
        for(sts=0;sts<a.length();++sts){
            if(a[sts]!='0'){
                break;
            }
        }
        for(int i=sts;i<a.length();++i){
            ans[a[i]-48]++;
        }


    }
    for(int i=0;i<10;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}
