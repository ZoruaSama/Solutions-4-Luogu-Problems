#include <stdio.h>
#include <stdlib.h>

void divide(int i, int j);

void gb_swap(int left, int right);

int zorua_atoi(const char *st, int stlen);

int zorua_len(const char *st);

int array[18] = {5, 1, 16, 4, 3, 19, 12, 7, 13, 17, 8, 6, 11, 2, 14, 0, 9, 10};

int main0(int argv, char **argc) {
    int length = sizeof(array) / sizeof(int);
    divide(0, length - 1);
    printf("数组长度 %d\n", length);
    for (int t = 0; t <= length - 1; t++) {
        printf("%d ", *(array + t));
    }

    return 0;
}

int main1(int argv, char **argc) {
    char num1[15];
    char num2[15];
    int a_1 = 0, a_2 = 0;//一个存储7位 一个存储8位
    int b_1 = 0, b_2 = 0;
    printf("请输入两个数字, 用空格隔开:");
    scanf("%s%s", num1, num2);
    if (zorua_len(num1) > 7) {
        a_1 = zorua_atoi(num1, zorua_len(num1) - zorua_len(num1 + zorua_len(num1) - 7));
        a_2 = zorua_atoi(num1 + zorua_len(num1) - 7, 0);

    } else {
        a_2 = zorua_atoi(num1, 0);
    }
    if (zorua_len(num2) > 7) {
        b_1 = zorua_atoi(num2, zorua_len(num2) - zorua_len(num2 + zorua_len(num2) - 7));
        b_2 = zorua_atoi(num2 + zorua_len(num2) - 7, 0);

    } else {
        b_2 = zorua_atoi(num2, 0);
    }
    printf("%d%d + ", a_1, a_2);
    printf("%d%d = ", b_1, b_2);
    printf("%d%d\n", a_1 + b_1 + (a_2 + b_2) / 10000000, (a_2 + b_2) % 10000000);
//    printf("%d %d", zorua_len(num1),zorua_atoi((num1)));

    return 0;
}

//归并排序练习
int length = sizeof(array) / sizeof(int);

int main(int argv, char **argc) {
//    main0(argv,argc);
    main1(argv, argc);

}

int zorua_len(const char *st) {
    int i = 0;
    for (;; ++i) {
        if (*(st + i) == '\0') { break; }
    }
    return i;
}

int zorua_atoi(const char *st, int stlen) {
    int result = 0;
    for (int i = 0;; ++i) {
        if (*(st + i) == '\0') { break; }
        if (i == stlen && stlen != 0) { break; }
        result = result * 10 + *(st + i) - 48;
    }
    return result;
}

void divide(int i, int j) {
    if (i < j) {
        divide(i, (i + j) / 2);
        divide((i + j) / 2 + 1, j);
        gb_swap(i, j);
    }
}

void gb_swap(int left, int right) {
    //printf("%d:%d %d:%d\n",i,array[i],j,array[j]);
    int i = left;
    int mid = (left + right) / 2;
    int j = mid + 1;
    int t = 0;
    //int temp[15];   //临时存放的数组
    int *temp = (int *) malloc((length) * sizeof(int));
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            *(temp + t++) = array[i++];
        } else {
            *(temp + t++) = array[j++];
        }
    }
    while (i <= mid)
        *(temp + t++) = array[i++];
    while (j <= right)
        *(temp + t++) = array[j++];
    t = 0;
    while (left <= right)
        array[left++] = *(temp + t++);

}