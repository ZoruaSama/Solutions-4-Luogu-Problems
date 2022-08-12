#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pIndex = 0;
int mode = 0;
int memory = 0;

char data[] = "//<<default>>";
//<<functions_pre>>





typedef struct table {
    struct table *prev;
    int index;
    int data;
    struct table *next;
} ptable;

ptable *pTable, *pPresent, *pNew, *pPtr;
void pre() {
    pTable = (struct table *) malloc(sizeof(struct table));
    pTable->prev = NULL;
    pTable->data = 0;
    pPresent = pTable;
    pPtr = pPresent;
}

void new(int data) {
    pNew = (struct table *) malloc(sizeof(struct table));
    pNew->index = pIndex++;
    pNew->data = data;
    pNew->prev = pPresent;
    pNew->next = NULL;
    pPresent->next = pNew;
    pPresent = pPresent->next;
}
void mode_change(){
    mode = (mode+1) % 2;
}
void input(){
    if(mode == 0){
        int a;
        scanf("%d",&a);
        pPtr->data = a;
    }
    else if(mode==1){
        char a;
        scanf("%c",&a);
        pPtr->data = a;
    }
}
void read() {

    if(mode == 0){
        printf("%d",(int) (pPtr->data));
    }
    else if(mode==1){
        printf("%c",(char) (pPtr->data));
    }
}

void right() {
    if (pPtr->next == NULL) {
        new(0);
    }
    pPtr = pPtr->next;
}

void left() {
    if (pPtr->prev != pTable) {
        pPtr = pPtr->prev;
    }
}

void plus(){
    pPtr->data ++;
}
void minus(){
    pPtr->data --;
}
void jump(int id){
    pPtr = pTable;
    while(pPtr->index != id){
        right();
    }
    return ;
}
void prev_check(int id){
    memory = pPtr->index;
    if(id>=0){
        jump(id);
    }
    else{
        memory = -1;
    }

}
void end_check(){
    if(memory>=0){
        jump(memory);
    }

}
//<<functions>>
int main(int argv, char **argc) {
    pre();
    if (strlen(data) == 0) {
        new(0);
    } else {
        int i;
        for (i = 0; i < strlen(data); i++) {
            new(data[i]);

        }

    }
    pPtr = pPtr->next;

    //以上为程序的初始化步骤

//<<content>>

    printf("\\n");
    system("pause");
    return 0;
}