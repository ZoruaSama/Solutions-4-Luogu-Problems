#include <stdio.h>
int select(int* a,int p,int r,int k){
    if(r-p<75){
        //一个任意的排序算法
        return a[p+k-1];
    }
}
int main() {
    int array[] = {197, 373, 268, 105, 269, 127, 431, 87, 96, 86, 62, 394,
                   392, 176, 250, 416, 450, 348, 380, 319, 134, 296, 355,
                   71, 413, 263, 405, 29, 384, 329, 414, 322, 430, 316, 384,
                   82, 35, 296, 25, 474, 413, 376, 198, 205, 196, 27, 29, 30,
                   221, 204, 445, 366, 411, 145, 486, 428, 429, 148, 206, 226,
                   101, 298, 378, 360, 239, 401, 417, 259, 143, 193, 286, 442,
                   406, 262, 311, 241, 331, 499, 114, 33, 252, 188, 499, 480,
                   412, 420, 49, 364, 430, 39, 388, 455, 353, 34, 442, 25,
                   345, 116, 446, 161};
    printf("%d",select(array,0,69,4));

    return 0;
}