#include <iostream>
#include <time.h>
using namespace std;
string s1,s2; //NOLINT
int kmpnext[101]={0};


void nexts(string s){
    for(int i=0;i<s.length();++i){
        kmpnext[i+1]=1;
        for(int j=i-1;j>=1;--j){
            //cout<< s.substr(0,j)<<' '<<s.substr(i-j+1,j)<<endl;
            if(s.substr(0,j) == s.substr(i-j,j)){
                kmpnext[i]=j+1;
                break;
            }
        }
        //cout<<"========"<<endl;
    }
    kmpnext[0]=0;
}
int bf(string a,string b){
    for(int i=0;i<a.length();++i){
        int j;
        for(j=0;j<b.length();++j){
            if(a[i+j]!=b[j]){
                break;
            }
        }
        if(j==b.length()) return i;
    }
    return -1;
}
int kmp(string a, string b,int p){
    https://blog.csdn.net/wangjichang1/article/details/8760931

    int k=p,j;
    while(k < a.length()){
        //cout<<"查找在"<<k<<endl;
        j=0;
        while(a[k+j] == b[j] && j < b.length())
        { j++;}
        if(j == b.length()){
            return k;
        }else{
            if(j-kmpnext[j+1]==0 || j==0){
                k+=1;
            }else{
                //cout<<"加上"<<j<<'-'<<kmpnext[j]<<endl;
                k+=j-kmpnext[j];
            }
        }
    }
    return -1;
}
int main() {

    cin>>s1>>s2;
    //s1=" "+s1;
    nexts(s2);
    int k=-1;
    do{
        k = kmp(s1,s2,k+1)+1;
        if(k!=0) cout<<k<<endl;
    }while(k!=0);
    cout<<0<<' '<<0<<' ';
    for(int i=2;i<s2.length();++i){
        cout<<kmpnext[i]<<' ';
    }
    return 0;
}
//  https://www.bilibili.com/video/BV1S64y1u74P?from=search&seid=11909842224884745085
//  abcdefghijabcdefghijabcdefghijabcdefghabcdefghijkabcabcijabcdefghijabcdefghijabcdefghijabcdefghijkabcdefghijabcdefghiabcj
//  abcdefghijkabcabc
/*
inline void get_next(string s) //求出next数组
{ //next数组是从 S[0到i-1]前子串 的前缀后缀最大值
    int t1=0,t2;
    kmpnext[0]=t2=-1;
    while(t1<s.length())
        if(t2==-1 || s[t1]==s[t2]) //类似于KMP的匹配
            kmpnext[++t1]=++t2;
        else t2=kmpnext[t2];//失配
}
int getnext(string s){//cLen为串ch的长度
    int cLen=s.length();
    kmpnext[1] = 0;
    int i = 1,j = 0;
    while(i<=cLen){
        if(j==0||s[i]==s[j]) kmpnext[++i] = ++j;
        else j = kmpnext[j];
    }
}

    for(int i=1;i<=s1.length()-1;++i){
        while(p&&s2[p+1]==s1[i]) p=kmpnext[p];
        if(s2[p+1]==s1[i]) p++;
        if(p==s2.length()){
            cout<<i-s2.length()+1<<endl;
            p=kmpnext[p];
        }
    }
 */

/*
cout<<endl;
    clock_t startTime = clock();
    for(int i=0;i<1000000;++i) bf(s1,s2);
    cout<<bf(s1,s2)<<endl;
    clock_t endTime = clock();
    cout<<endTime-startTime<<endl;
    startTime = clock();
    //for(int i=0;i<1000000;++i) kmp(s1,s2);
    cout<<kmp(s1,s2)<<endl;
    endTime = clock();
    cout<<endTime-startTime<<endl;
 */