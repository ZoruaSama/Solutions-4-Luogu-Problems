#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
    string name;
    int y;
    int m;
    int d;
    int index;
};
stu stus[100];
bool cmp(stu f,stu s){
    int a = f.y*10000 + f.m*100 + f.d;
    int b = s.y*10000 + s.m*100 + s.d;
    if(a==b){
        return (f.index > s.index);
    }
    return (a < b);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>stus[i].name;
        cin>>stus[i].y;
        cin>>stus[i].m;
        cin>>stus[i].d;
        stus[i].index=i;
    }
    stable_sort(stus,stus+n,cmp);
    for(int i=0;i<n;++i){
        cout<<stus[i].name<<endl;
    }
    return 0;
}
