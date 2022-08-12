//#include <iostream>
//using namespace std;
//const int maxn=110;
//int n;
//long long a[maxn];
//int main() {
//    cin>>n;
//    for(int i=0;i<=n;++i){
//        cin>>a[i];
//    }
//    for(int i=1;i<=n;++i){
//        cout<<a[i]*i<<endl;
//    }
//    return 0;
//}

//===========================   1

//考虑两个等长的正整数组$a[1,...,n]$和$b[1,...,n]$，如果满足以下条件则称这两个序列耦合：
//对任何整数$i,j\in[1,n]$，如果$a[i]<a[j]$则$b[i]<= b[j]$。现在要求判断两个正整数组是否耦合。

//输入
//
//        输入为多测试点，故第一行为一个正整数$T$。
//
//接下来一共有$T$个测试点，每个测试点有三行输入，三行输入构成如下：
//
//第一行，一个正整数$n$。
//第二行，$n$个正整数，用空格隔开，表示$a$。
//第三行，$n$个正整数，用空格隔开，表示$b$。
//输出
//
//        $T$行，每一行一个$Yes$或者$No$，表示是否耦合。


//===========================   2
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int maxn=1e6+10;
//int t,n;
//struct p{
//    int a,b;
//}P[maxn];
//bool cmp(p &x,p &y){
//    return x.a<y.a || (x.a==y.a&&x.b<y.b);
//}
//bool cmp2(p &x,p &y){
//    return x.b<=y.b;
//}
//int main() {
//    cin>>t;
//    while(t--){
//        cin>>n;
//        for(int i=1;i<=n;++i){
//            cin>>P[i].a;
//        }
//        for(int i=1;i<=n;++i){
//            cin>>P[i].b;
//        }
//        sort(P+1,P+1+n,cmp);
//        //判断B序列是否是一个递增序列
////                for(int i=1;i<=n;++i){
////                    cout<<P[i].a<<' ';
////                }
////                cout<<endl;
////                for(int i=1;i<=n;++i){
////                    cout<<P[i].b<<' ';
////                }
////                cout<<endl;
//        bool flag=true;
//        for(int i=1;i<=n-1;++i){
//            if(P[i].b>P[i+1].b){
//                flag=false;
//                break;
//            }
//        }
//        if(flag){
//            cout<<"Yes"<<endl;
//        }else{
//            cout<<"No"<<endl;
//        }
//    }
//    return 0;
//}
//


//===========================   3
//#include <iostream>
//using namespace std;
//int n;
//int a,b,c,d,e,f,g,h;
//int a_c,e_f,b_d,h_g;
//int cnt=0;
//int main(){
//    cin>>n;
//    for(a_c=2;a_c<=2*n-2;++a_c){
//        for(b_d=2;b_d<=2*n-2;++b_d){
//            for(e_f=0;e_f<=2*n-2;++e_f){
//                for(h_g=0;h_g<=2*n-2;++h_g){
//                    if(a_c*e_f+b_d*h_g==(a_c+b_d)*n+e_f+h_g){
//                        ++cnt;
//                    }
//                }
//            }
//        }
//    }
//    cout<<cnt;
//    return 0;
//}

//===========================   4

#include <iostream>
using namespace std;
const int mod=998244353;
//[abc][abc][abc] 数据范围1e18
// n至少敲3次  字母数量k至少要到u(21)
//3:
//  bnu
//4:
//  bnu* k
//  *bnu k
//  2k
//5:
//  **bnu k^2
//  bnu** k^2
//  *bnu* k^2
//  3k^2
//6:
//  bnu*** k^3
//  *bnu** k^3
//  **bnu* k^3
//  ***bnu k^3
//  4k^3
//7:
//  *******
//  5k^4

//n:
//  (n-2)k^(n-3)

//
//#define ll long long
//ll pow_mod(ll a,ll b,ll c){
//    ll ans=1;
//    a=a%c;
//    while(b>0){
//        if(b%2==1) ans=(ans*a)%c;
//        b/=2;
//        a=(a*a)%c;
//    }
//    return ans%mod;
//}
int main(){
//    int t;
//    ll n,k;
//    cin>>t;
//    while(t--){
//        cin>>n>>k;
//        //  (n-2)k^(n-3)
//        cout<<(((n-2)%mod)*pow_mod(k,n-3,mod)+mod)%mod<<endl;
//    }
    cout<<system("echo 456456879>in.txt");
    cout<<system("python a.py<\"in.txt\">a.txt");
    return 0;
}

//===========================
//#include <iostream>
//using namespace std;
//const int maxn=5e6+10;
//int n,q;
//int a[maxn];
//int b[maxn];
//int head[maxn];
//int tot;
//struct e{
//    int to,w,next;
//}E[maxn];
//void addEdge(int u,int v,int w){
//    ++tot;
//    E[tot].to=v;
//    E[tot].w=w;
//    E[tot].next=head[u];
//    head[u]=tot;
//}
//
//
//int u,v;
//
//int main() {
//    cin>>n>>q;
//    //有q次询问
//    for(int i=1;i<=n;++i){
//        for(int j=i+1;j<=n;++j){
//            //判断ij是否 互质
//
//        }
//    }
//    for(int i=1;i<=q;++i){
//        cin>>u>>v;
//    }
//    return 0;
//}



//===========================   5
//#include <iostream>
//using namespace std;
//const int maxn=5e6+10;
//int n,q;
//int head[maxn];
//int tot;
//struct e{
//    int to,w,next;
//}E[maxn];
//int f[maxn]; //dijkstra用的res变量
//bool vis[maxn]; //dijkstra用的vis变量
//int path[maxn];//记录路线的前驱节点
//int res[maxn];//记录结果路线的序列
//
//void addEdge(int u,int v,int w){
//    E[++tot].to=v;
//    E[tot].w=w;
//    E[tot].next=head[u];
//    head[u]=tot;
//}
//最短路问题 要问具体路径
// dijkstra
//int gcd(int a,int b){
//    return b==0 ? a: gcd(b,a%b);
//}

//void dijkstra(int s){
//    for(int i=1;i<=n;++i){
//        f[i]=maxn-1;
//        path[i]=0;
//        vis[i]=false;
//    }
//    f[s]=0;
//    for(int k=1;k<=n-1;++k){
//        int min=maxn-1;
//        int p=s;
//        //选点
//        for(int kk=1;kk<=n;++kk){
//            if(!vis[kk]){
//                if(f[kk]<min){
//                    p=kk;
//                    min=f[kk];
//                }
//            }
//        }
//        vis[p]=true;
//        //松弛
//        for(int i=head[p];i;i=E[i].next){
//            int w=E[i].w;
//            int v=E[i].to;
//            if(!vis[v] && f[p]+w<f[v]){
//                f[v]=f[p]+w;
//                path[v]=p;
//            }
//        }
//    }
//}


//int main() {
//    cin>>n>>q;
//    //有q次询问
//    for(int i=1;i<=n;++i){
//        for(int j=i+1;j<=n;++j){
//            if(gcd(i,j)==1){
//                //互质就加个路线
//                addEdge(i,j,1);
//            }
//        }
//    }
//    for(int i=1;i<=q;++i){
//        int u,v;
//        cin>>u>>v;
//        dijkstra(u);
//        if(f[v]==maxn-1){
//            cout<<-1<<endl;
//        }else{
//            cout<<f[v]<<' ';
//            int cnt=0;
//            cout<<u<<' ';
//            while(path[v]!=0){
//                res[++cnt]=v;
//                v=path[v];
//            }
//            for(int j=cnt;j>=1;--j){
//                cout<<res[j]<<' ';
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}

//class a{
//public:
//    static a *ptr;
//    void aaa(){
//        a *ptr=new a();
//
//    }
//};