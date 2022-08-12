#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    string w;
    cin>>w;
    string s;
    int cnt=0;
    int pos=-1;
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    scanf("%*[^\n]");
    scanf("%*c"); //清理输入缓冲区
    getline(cin,s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    w=" "+w+" ";
    s=" "+s+" ";
    pos = s.find(w);
    int ppos=pos;
    while(ppos!=-1 || ppos>=(int)s.length()){
        cnt++;
        ppos = s.find(w,ppos+1);
    }
    if(pos==-1){
        cout<<-1;
        return 0;
    }
    cout<<cnt<<' '<<pos;
    return 0;
}



/*
int main() {
    string w;
    cin>>w;
    string s;
    int cnt=0;
    int pos=-1;
    int sum=0;
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    while(cin>>s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(w==s){
            cnt++;
            if(pos==-1){
                pos=sum;
            }
        }
        sum+=(int)s.length()+1;
    }
    if(pos==-1){
        cout<<-1;
        return 0;
    }
    cout<<cnt<<' '<<pos;
    return 0;
}


*/