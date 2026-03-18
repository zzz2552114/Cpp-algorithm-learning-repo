#include <stdio.h>

int main()
{
    int int_arr[5];
    printf("please enter 5 ints here:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &int_arr[i]);
    }
    printf("what you input are: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", int_arr[i]);
    }
}