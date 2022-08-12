#include<queue>
#include<iostream>

using namespace std;
struct node{
    int num;
    int id;
    bool operator<(const node&a) const{
        return a.num>num;
    }
};
priority_queue<node> q;


int n,k;
int c;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>c;
        q.push(node{c,i});
        if(i>=k){
            while(q.top().id<i-k+1) q.pop();
            cout<<q.top().num<<endl;
        }
    }
}