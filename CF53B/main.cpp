#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define inf 1e9
using namespace std;
inline int read(){
    int x,f=1; char c;
    while(!((c=getchar())>='0'&&c<='9')) if(c=='-') f=-1;
    x=c-'0';
    while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
    return x*f;}
inline void up(int &a,const int &b){if(a<b)a=b;}
const int maxn = 36000;
const int maxc = 1005;
int n,m;
struct data{int t,x;};
struct node{
    int type,sig;
    data x,y;
    int to[2];}op[maxn];
char str[110];
void Input(){
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        if(str[0]=='v'){
            op[i].type=1;
            op[i].x=(data){1,read()};
            scanf("%s",str); op[i].sig=str[0]=='+'?1:-1;
            scanf("%s",str); op[i].y.t=str[0]=='v',op[i].y.x=read();}
        else if(str[0]=='s'){
            op[i].type=2;
            op[i].to[0]=read(),op[i].to[1]=read();}
        else{
            op[i].type=3;
            scanf("%s",str); op[i].x.t=str[0]=='v'; op[i].x.x=read();
            scanf("%s",str); op[i].y.t=str[0]=='v'; op[i].y.x=read();
            op[i].to[0]=read(),op[i].to[1]=read();}
        if(op[i].to[0]<1||op[i].to[0]>n) op[i].to[0]=n+1;
        if(op[i].to[1]<1||op[i].to[1]>n) op[i].to[1]=n+1;}
}
struct Block{
    int l,r;
    int vy[2],vd[2],vc[2],ful;
    vector<int>ansi;
}b[maxn]; int bn;
int bel[maxn];
int ans;
int now[20];
int t[maxn],tp;
int nowb;
void dfs(const int i){
    if(i<b[nowb].l||i>b[nowb].r){
        if(ans<now[1]){
            b[nowb].vy[1]=i,b[nowb].vd[1]=now[2]-op[1].y.x;
            ans=now[1];
            b[nowb].ansi.clear();
            for(int i=1;i<=tp;i++) b[nowb].ansi.pb(t[i]);}
        return;
    }
    if(op[i].type==1){
        int tmp=op[i].y.t?now[op[i].y.x]:op[i].y.x;
        now[op[i].x.x]+=tmp*op[i].sig;
        dfs(i+1);
        now[op[i].x.x]-=tmp*op[i].sig;}
    else if(op[i].type==2){
        int tc=0;
        t[++tp]=tc,dfs(op[i].to[tc]),tp--;
        t[++tp]=!tc,dfs(op[i].to[!tc]),tp--;}
    else{
        int x=op[i].x.t?now[op[i].x.x]:op[i].x.x,y=op[i].y.t?now[op[i].y.x]:op[i].y.x;
        if(x<y) dfs(op[i].to[0]);
        else dfs(op[i].to[1]);}
}
int f[maxn][maxc],p[maxn][maxc],pc[maxn][maxc];
void dp(){
    for(int i=1;i<=bn;i++)
        for(int j=0;j<maxc;j++)
            f[i][j]=-inf;
    f[1][op[1].y.x]=0;
    for(int i=1;i<bn;i++)
        for(int j=0;j<maxc;j++)
            if(f[i][j]!=-inf){
                if(j+b[i].vd[0]>=0){
                    int y=b[i].vy[0],nj=j+b[i].vd[0];
                    if(f[bel[y]][nj]<f[i][j]+b[i].vc[0]) f[bel[y]][nj]=f[i][j]+b[i].vc[0],p[bel[y]][nj]=i,pc[bel[y]][nj]=0;}
                if(j+b[i].vd[1]>=0){
                    int y=b[i].vy[1],nj=j+b[i].vd[1];
                    if(f[bel[y]][nj]<f[i][j]+b[i].vc[1]) f[bel[y]][nj]=f[i][j]+b[i].vc[1],p[bel[y]][nj]=i,pc[bel[y]][nj]=1;}
            }
}
int main(){
    scanf("%d%d",&n,&m);
    srand(1000007);
    Input();
    int ssum=0;
    b[bn=1].l=2;
    for(int i=2;i<=n;i++){ if(op[i].type==1&&op[i].x.x==12&&op[i].y.t&&op[i].y.x==12&&op[i].sig==-1){
            b[bn].r=i; b[bn].ful=0;
            for(int j=b[bn].l;j<=b[bn].r;j++) {
                bel[j]=bn;
                if(op[j].type==2&&!b[bn].ful)
                {
                    b[bn].ful=1;
                    b[bn].vy[0]=op[j].to[1],b[bn].vd[0]=0,b[bn].vc[0]=0;
                }
            }
            ans=-inf,nowb=bn; now[2]=op[1].y.x; dfs(b[bn].l);
            b[bn].vc[1]=ans;
            ssum-=b[bn].vd[1];
            b[++bn].l=i+1;}
    }
    bel[n+1]=bn; b[bn].r=n+1;
    for(int i=b[bn].l;i<=b[bn].r;i++) bel[i]=bn;
    dp();
    int x=bn,y=0;
    for(int i=1;i<maxc;i++)
        if(f[x][i]>f[x][y])
            y=i;
    tp=0;
    while(x!=1){
        int i=p[x][y];
        if(pc[x][y]==0){
            if(y+b[i].vd[1]>=0) t[++tp]=1;
            y-=b[i].vd[0];
        }
        else{
            for(int j=(int)b[i].ansi.size()-1;j>=0;j--) t[++tp]=b[i].ansi[j];
            y-=b[i].vd[1];}
        x=i;}
    for(int i=tp;i>=1;i--) printf("%d\n",t[i]+1);
    return 0;
}