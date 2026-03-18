#include <stdio.h>

int main(){
    // 先while循环
    int i = 1;
    int sum_2x = 0;
    while (i <= 100)
    {
        if (i % 2 ==0){
            sum_2x = sum_2x + i;
        }
        i = i + 1;
    }
    printf("while循环轮:\n");
    printf("1-100中所有偶数和为:%d\n", sum_2x);

    sum_2x = 0;
    i = 1;
    do{
        if (i % 2 == 0)
        {
            sum_2x = sum_2x + i;
        }
        i = i + 1;
    } while (i < 101);
    printf("do-while循环轮:\n");
    printf("1-100中全体偶数和为%d:", sum_2x);
}