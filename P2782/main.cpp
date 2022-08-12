#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=2e5+1;
const int maxx=1e6;
int n;
struct g{
	int c1,c2;
}mp[maxn];
int tree[maxx]={0};
bool cmp(g a,g b){
	return a.c1 < b.c1;
}
int lowbit(int x){
	return x&(-x);
}
void add(int x,int v){
	for(int i=x;i<=maxx;i+=lowbit(i)){
		tree[i] = max(tree[i], v);
	}
}
int ask(int x){
	int ret=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		ret = max(tree[i],ret);
	}
	return ret;
}
int main(){
	//freopen("P2782.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;++i){
		//cin>>mp[i].c1>>mp[i].c2;
		cin>>mp[i].c2;
	}
	//sort(mp+1,mp+1+n,cmp);
	/*
	for(int i=1;i<=n;++i){
		cout<<mp[i].c1<<' '<<mp[i].c2<<endl;
	}
	*/

	//Solve the LIS problem with Binary Tree Array
	// 以 i 结尾的最长上升子序列的长度为tree[i]
	int ans=0;
	for(int i = 1 ; i <= n; ++i){
		int x = ask(mp[i].c2) + 1;
		ans = max(ans, x);
		add(mp[i].c2, x);
	}
	cout<<ans<<endl;
	return 0;
}