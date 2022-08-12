#include <iostream>
using namespace std;
int trans[27]={0}; //65-60
int trans_[27]={0};
int cnt=0;
int main() {
    string s1,s2,s3;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();++i){
        if(trans[s1[i]-'A'+1]==0 && trans_[s2[i]-'A'+1]==0){
            trans[s1[i]-'A'+1]=s2[i]-'A'+1;
            trans_[s2[i]-'A'+1]=s1[i]-'A'+1;
            cnt++;
        }else{
            if(trans[s1[i]-'A'+1]!=s2[i]-'A'+1){
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    if(cnt<26){
        cout<<"Failed"<<endl;
        return 0;
    }
    cin>>s3;
    for(int i=0;i<s3.length();++i){
        cout<<(char)(trans[s3[i]-'A'+1]+'A'-1);
    }
    return 0;
}
