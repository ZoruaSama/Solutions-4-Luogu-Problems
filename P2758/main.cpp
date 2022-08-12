#include <iostream>
#include <algorithm>
using namespace std;
int min3(int a,int b,int c){
    return min(a,min(b,c));
}
int same(string a,string b){
    int i,j;
    int m=0,k=0;
    for(i=0;i<a.length();++i){
        for(j=k;j<b.length();++j){
            if(a[i]==b[j]){
                m++;
                k=j;
                break;
            }
        }
    }
    return m;
}
int main() {
    string a,b;
    cin>>a>>b;
    int f[205][205];
    for(int i=0;i<=a.length();++i) f[i][0] = i;
    for(int i=0;i<=b.length();++i) f[0][i] = i;
    for(int i=0;i<a.length();++i){
        for(int j=0;j<b.length();++j){
            f[i+1][j+1]=min3(f[i][j+1]+1,f[i+1][j]+1,f[i][j]+(a[i]!=b[j]));
        }
    }
    cout<<f[a.length()][b.length()]<<endl;

    //---------------- 好像不太行的解法
    f[same(a,b)][same(a,b)]=0;
    int m;int i=a.length(),j=b.length();
    while(true){
        if(i>j){
            i--;
            m++;
        }
        else if(j>i){
            j--;
            m++;
        }
        else if(i==j && i!=same(a,b)){
            i--;j--;
            m++;
        }
        else if(i==j && i==same(a,b)){
            break;
        }
    }
    cout<<m;
    return 0;
}
