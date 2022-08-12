#include <stdio.h>
#include <string.h>

int main() {
    char s[502]={0};
    char a[20];
    int k;
    scanf("%d",&k);
    scanf("%s",a);
    for(int i=0;i<501;++i){
        s[i]='0';
        if(i==500-k){
            s[i]='1';
        }
    }
    int carry = 0;
    int i,j;
    for(i=500,j=strlen(a)-1;j>=0;--j,--i){
        int r = s[i] + a[j] - 96 + carry;
        carry = (s[i] + a[j] - 96 + carry)/10;
        s[i] = r % 10 + 48;
    }
    if(carry != 0){
        s[i]=carry+48; //注意最高位
    }
    for(int i=0;i<501;++i){
        if(s[i]!='0'){
            printf("%s",s+i);
            break;
        }
    }

    return 0;
}
//    char s[502];
//    s[0]='1';
//    int n;
//    char a[20];
//    int d;
//    for(int i=1;i<=502;++i){
//        s[i]='0';
//    }
//    scanf("%d",&n);
//    if(n!=0){
//        scanf("%s",a);
//    }
//    else{
//        scanf("%d",&d);
//    }
//    s[n- (strlen(a))+1]='\0';
//    if(n!=0){
//        printf("%s%s",s,a);
//    } else{
//        printf("%d",d+1);
//    }