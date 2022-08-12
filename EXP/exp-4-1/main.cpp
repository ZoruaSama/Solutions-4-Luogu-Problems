#include <iostream>
using namespace std;
int f[100][100]={0};
bool x[100]={false};
int w[100];
int v[100];
int n,m;
void Traceback(int c){
    for(int i=1;i<n;i++){
        if(f[i][c]==f[i+1][c]){
            x[i]=true;
        }else{
            x[i]=false;
            c-=w[i];
        }
        x[n] = f[n][c] == 0;
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<w[i]){
                f[i][j]=f[i-1][j];
            }else{
                f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    Traceback(m);
    for(int i=1;i<=n;i++){
        cout<<x[i]<<' ';
    }
    return 0;
}
