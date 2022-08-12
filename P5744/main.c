#include <stdio.h>
struct student{
    char name[20];
    int age;
    int grade;
} a[200];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",&a[i].name);
        scanf("%d",&a[i].age);
        scanf("%d",&a[i].grade);
    }
    for(int i=0;i<n;++i){
        printf("%s ",a[i].name);
        printf("%d ",a[i].age+1);
        if((int)(a[i].grade*1.2)>600){
            printf("%d ",600);
        }else{
            printf("%d ",(int)(a[i].grade*1.2));
        }
        printf("\n");
    }
    return 0;
}
