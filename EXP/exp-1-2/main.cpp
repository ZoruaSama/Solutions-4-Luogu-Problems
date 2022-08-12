#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
int a[1000001];
int getStandard(int i,int j){
    int key=a[i];
    while(i<j){
        while(i<j && a[j] >= key){ j--;}
        if(i<j){
            a[i]=a[j];
        }
        while(i<j && a[i] <= key){ i++; }
        if(i<j){
            a[j]=a[i];
        }
    }
    a[i]=key;
    return i;

}
void QuickSort(int low, int high) {
    if (low < high) {
        int standard = getStandard(low, high);
        QuickSort(low, standard - 1);
        QuickSort(standard + 1, high);
    }
}
int main() {
    int n;
    cin>>n;
    fstream file;
    file.open("in.txt", ios::in);
    if(file){
        freopen("in.txt","r",stdin);
    }
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    clock_t startTime = clock();
    QuickSort(0,n-1);
    clock_t endTime = clock();
    for(int i=n-1000;i<n;++i){
        cout<<a[i]<<' ';
    }
    cout<<endl<<"ºÄÊ±"<<(double) (endTime-startTime)/1000<<"Ãë¡£";
    system("pause");
    return 0;
}