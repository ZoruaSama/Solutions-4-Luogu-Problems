#include <stdio.h>

int main() {
    int n;
    char c[26];
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%c",c+i);
        getchar();
    }
    for(int i=2;i<=n;i++){
        sum += (c[i] != c[i-1]);
    }
    printf("%d",sum);
    return 0;
}


//    for(int i=0;i<n;i++){
//        scanf("%c\n",&c);
//        if(m != c && c!=10){
//            sum++;
//            m = c;
//        }
//    }


/*
 *
 *
n=int(input())
m="0"
sum=1
for i in range(0,n):
  a=input()
  if(m != a):
    sum += 1
    m = a

print(sum)
 *
 * */