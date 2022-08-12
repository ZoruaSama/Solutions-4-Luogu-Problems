#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct node{
    string str;
    int step;
};
queue <node> q;
map <string,bool> re;
int main() {
    string a,b;
    cin>>a>>b;
    string x[6],y[6];
    int n=0;
    while(cin>>x[n]>>y[n]){
            n++;
    }
    n--;
    node s;
    s.str=a;
    s.step=0;
    q.push(s);
    while(!q.empty()){
        if(q.front().str==b){
            cout<<q.front().step;
            return 0;
        }
        if(q.front().step==10){
            q.pop();
            continue;
        }
        string t=q.front().str;
        if(re.count(t)){
            q.pop();
            continue;
        }
        re[t]=true;
        for(int i=0;i<=n;++i){
            int p=0;
            while(t.find(x[i],p)!=-1){
                p=t.find(x[i],p);
                node m;
                m.str=t.substr(0,p)+y[i]+t.substr(p+x[i].length());
                m.step=q.front().step+1;
                q.push(m);
                p++;
            }
        }
        q.pop();
    }
    cout<<"NO ANSWER!";
    return 0;
}
