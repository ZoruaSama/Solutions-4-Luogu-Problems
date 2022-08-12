#include <iostream>
#include <map>
using namespace std;
int main() {
    string s;
    int num=0;
    char m;
    map<char,int> mp;
    mp['C']=0;
    mp['H']=0;
    mp['O']=0;
    cin>>s;
    s=s+'Z';
    for(int i=0;i<s.length();++i){
        char ch = s[i];
        if(isalpha(ch)){
            if(num!=0){
               mp[m]+=num-1;
               num=0;
            }
            mp[ch]++;
            m=ch;
        }else{
            num*=10;
            num+=ch-48;
        }
    }
    if(mp['H']%2!=0){
        mp['C']*=2;
        mp['H']*=2;
        mp['O']*=2;
    }
    if((mp['H']-2*mp['O'])%4!=0){
        mp['C']*=2;
        mp['H']*=2;
        mp['O']*=2;
    }
    cout<<mp['C']<<' '<<mp['H']/2;
    return 0;
}
