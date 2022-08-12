#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;
int a[1000001];
int cnt=0;
int search(int k,int i,int j){
    cnt++;
    int m=(i+j)/2;
    if(i>=j){
        if(k!=a[m])
            return -1;
    }else{
        if(k==a[m]){
            return m+1;
        }else if(k>a[m]){
            return search(k,m+1,j);
        }else{
            return search(k,i,m-1);
        }
    }

}

int main() {
    int n,m;
    cin>>n>>m;
    fstream file;
    file.open("in.txt", ios::in);
    if(file){
        freopen("in.txt","r",stdin);
    }
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    clock_t startTime = clock();
    for(int i=0;i<1000;++i){
        cout<<search(m,0,n-1);
    }
    clock_t endTime = clock();
    cout<<endl<<"耗时"<<(double) (endTime-startTime)/1000<<"秒。";
    cout<<endl<<"查找次数"<<cnt<<"次。";
    system("pause");
    return 0;
}