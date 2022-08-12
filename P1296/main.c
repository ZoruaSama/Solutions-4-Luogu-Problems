#include <stdio.h>
#include <math.h>
#define NUM 100000
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
int main() {
    int n,d;
    int count=0;
    int p[NUM];
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;++i){
        scanf("%d",p+i);
    }
    int i,j;
    quick_sort(p,0,n-1);
    int it = 1;
    for(int i=0;i<n;++i){
        while(it<n && p[it]-p[i]<=d)++it;
        --it;
        count+=it-i;
    }
    printf("%d",count);
    return 0;
}

//--- 快速排序
//    int key=p[0];
//    int i=0,j=n;
//    while(1){
//        while(i<j && p[--j]>=key);
//        while(i<j && p[++i]<=key);
//        if(i>=j) break;
//        p[i] = p[i] ^ p[j];
//        p[j] = p[i] ^ p[j];
//        p[i] = p[i] ^ p[j];
//    }
//    p[0]=p[j];

//---
//
//for(i=0;i<n;++i){
//int k=i;
//for(j=i+1;j<n;++j){
//if(p[j]<p[k]) k=j;
//}
//if(k!=i){
//p[i] = p[i] ^ p[k];
//p[k] = p[i] ^ p[k];
//p[i] = p[i] ^ p[k];
//}
//}