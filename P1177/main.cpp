#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
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
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        cout<<a[i]<<' ';
    }
    return 0;
}
