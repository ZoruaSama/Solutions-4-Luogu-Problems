#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p; //NOLINT
int n,k;
int main(){
    cin>>n>>k;
    cout<<0<<endl;
    for(int i=0;i<n-1;i++){
        int a;
        scanf("%d",&a); //NOLINT
        p.push(make_pair(a,i));
        while(p.top().second<=i-k) p.pop();
        printf("%d\n",p.top().first);
    }
}