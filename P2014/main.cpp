#include <iostream>
#include <vector>
using namespace std;
vector<int> k[302];
int s[302]={0};
int f[302][302]={0};
int n,m;
// f[i][j] ��ʾ ��i�ſ������j�ſ�
// f[0][M] ��ʾ ���մ�
int dfs(int x){
    for(int i=1;i<=m;++i){
        f[x][i]=s[x];
    }
    for(int i=0;i<k[x].size();++i){
        dfs(k[x][i]);
        for(int j=m;j>=1;--j){
            for(int l=0;l<=j-1;++l){
                f[x][j]=max(f[x][j],f[x][j-l]+f[k[x][i]][l]);
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a>>s[i];
        k[a].push_back(i);
    }
    m=m+1;
    dfs(0);
    cout<<f[0][m];
    return 0;
}
/*
for(int i=1;i<=m;++i){ //�ȶԵ�ǰ����ڵ���д��� ֻҪ�������ڵ�ǰ�ε����� �Ϳ�ѡ
        f[x][i]=s[x];   //�߽�����
    }
    for(int i=0;i<k[x].size();++i){ //��Ʒ
        dfs(k[x][i]); //��������ڵ���ӽڵ�
        for(int j=m;j>=1;j--){ //���    01����������
            for(int l=0;l<=j-1;++l){ //����   ���������l���ռ���� ������j-1 ��Ϊ���ڵ���Ҫ
               f[x][j]=max(f[x][j],f[x][j-l]+f[k[x][i]][l]);
            }
        }
    }
 */