#include <stdio.h>
#include <string.h>
int main() {
    int n;
    char s[200];
    int c;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        if(c==1){
            scanf("%s",s+strlen(s));
            printf("%s\n",s);
        }
        else if(c==2){
            int a,b;
            char ss[200];
            scanf("%d%d",&a,&b);
            strcpy(ss,s);
            int i;
            for(i=a;i<a+b;i++){
                s[i-a]=ss[i];
            }
            s[i-a]='\0';
            printf("%s\n",s);
        }
        else if(c==3){
            int a;
            char ss[100];
            scanf("%d%s",&a,ss);
            for(int i=strlen(s);i>=a;i--){
                s[i+strlen(ss)]=s[i];
                s[i]='Z';
            }
            for(int i=a;i<a+strlen(ss);i++){
                s[i]=ss[i-a];
            }
            printf("%s\n",s);
        }
        else if(c==4){
            char ss[100];
            scanf("%s",ss);
            int i;
            for(i=0;i<strlen(s);i++){
                int j;
                for(j=0;j<strlen(ss);j++){
                    if(ss[j]!=s[i+j]){
                        break;
                    }
                }
                if(j==strlen(ss)){
                    printf("%d\n",i);
                    break;
                }
            }
            if(i==strlen(s)){
                printf("-1\n");
            }
        }

    }
    return 0;
}
