#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(ll a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar((int)(a%10+48));
}
const int maxn=5e5+1;
int a[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int v){
    for(int i=x;i<=maxn;i+=lowbit(i)){
        a[i]+=v;
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=a[i];
    }
    return res;
}
vector<int> s;
vector<int> ss;
int getid(int x){
    return lower_bound(s.begin(),s.end(),x)-s.begin()+1;
}
ll ans=0;
int main() {
    int n,x;
    n=read();
    for(int i=1;i<=n;++i){
        x = read();
        s.push_back(x);
        ss.push_back(x);
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    for(int i=ss.size()-1;i>=0;--i){
        int id = getid(ss[i]);
        int res = ask(id-1);
        add(id,1);
        ans+=res;
    }
    cout<<ans;
    return 0;
}
