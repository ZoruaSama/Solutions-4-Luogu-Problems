#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string zhiwei[]={"BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong"};
int shangxian[]={1,2,2,4,7,25,2000000000};
struct data{
    string name;
    int zhiwei;
    int banggong;
    int dengji;
    int shunxu;
};
bool cmp_(data &a,data &b){
    return a.banggong > b.banggong ||  (a.banggong==b.banggong && (a.shunxu < b.shunxu));
}
bool cmp(data &a,data &b){
    return a.zhiwei < b.zhiwei || ((a.zhiwei==b.zhiwei) && a.dengji > b.dengji) ||
            ((a.zhiwei==b.zhiwei) && (a.dengji == b.dengji) && (a.shunxu < b.shunxu));
}
vector<data> datas;
int zhiwei2i(string &x){
    for(int i=0;i<7;++i){
        if(zhiwei[i]==x){
            return i;
        }
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        string s1,s2;
        int gx,lv;
        cin>>s1>>s2>>gx>>lv;
        datas.push_back(data{s1,zhiwei2i(s2),gx,lv,i});
    }
    int index=0;
    if(n>3){
        sort(datas.begin()+3,datas.end(),cmp_);
        for(int i=0;i<datas.size();++i){
            datas[i].zhiwei=index;
            shangxian[index]--;
            if(shangxian[index]==0){
                index++;
            }
        }
    }
    sort(datas.begin(),datas.end(),cmp);
    for(int i=0;i<datas.size();++i){
        cout<<datas[i].name<<' '<<zhiwei[datas[i].zhiwei]<<' '<<datas[i].dengji<<endl;
    }
    return 0;
}
