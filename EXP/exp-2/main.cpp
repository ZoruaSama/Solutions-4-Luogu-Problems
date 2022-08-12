#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;
int partition(int *L,int p,int r){
    int i=p;
    int j=r+1;
    int x=L[p];
    while(true){
        while(L[++i]<x && i<r);
        while(L[--j]>x);
        if(i>=j) break;
        swap(L[i],L[j]);
    }
    L[p]=L[j];
    L[j]=x;
    return j;
}

int select(int *L,int p,int r,int k){
    if(p==r) return L[p];
    int i=partition(L,p,r);
    int j=i-p+1;
    if(k<=j){
        return select(L,p,i,k);
    }else{
        return select(L,i+1,r,k-j);
    }
}
int L[1000001];
int main() {
    int n,m;
    cin>>n>>m;
    fstream file;
    file.open("in.txt", ios::in);
    if(file){
        freopen("in.txt","r",stdin);
    }
    for(int i=0;i<n;++i){
        cin>>L[i];
    }
    clock_t startTime = clock();
    for(int i=0;i<1000;++i){
        cout<<select(L,0,n-1,m);
    }
    clock_t endTime = clock();
    cout<<endl<<"ºÄÊ±"<<(double) (endTime-startTime)/1000<<"Ãë¡£";
    system("pause");
    return 0;
}
