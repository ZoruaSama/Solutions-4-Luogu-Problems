#include <iostream>
#include <algorithm>
using namespace std;
struct activity{
    int s;
    int f;
    int index;
};
activity a[1000];

bool cmp(const activity &first, const activity &second)
{
    if (first.f<=second.f) return true;
    return false;
}
void GreedySelector(int n,activity act[],bool set[]){
    set[1]=true;
    int j=1;
    for(int i=2;i<=n;i++){
        if(act[i].s>=act[j].f){
            set[i]=true;
            j=i;
        }
        else{
            set[i]=false;
        }
    }
}
int main(){
    int n;
    bool set[1000];
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].index;
        cin>>a[i].s;
        cin>>a[i].f;
    }
    sort(a,a+n,cmp);
    GreedySelector(n,a,set);
    for(int i=1;i<=n;i++){
        if(set[i]) cout<<a[i].index<<" ";
    }
    return 0;
}
/*
11
1 1 4
2 3 5
3 0 6
4 5 7
5 3 8
6 5 9
7 6 10
8 8 11
9 8 12
10 2 13
11 12 14
 */