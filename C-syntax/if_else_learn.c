#include <stdio.h>

int main()
{
    int user_type;
    double price;
    double pay;
    price = 3000;
    user_type = 1;
    if (user_type == 1)
    {
        if (price > 100)
        {
            pay = price * 0.95;
            printf("95percent discount");
        }
        else
        {
            pay = price;
            printf("no discount");
        }
    }
    else if (user_type == 2)
    {
        if (price > 200)
        {
            pay = price * 0.9;
            printf("90percent discount");
        }
        else
        {
            pay = price * 0.97;
            printf("97percent discount");
        }
    }
    else
    {
        printf("vip valueErr");
    }
    printf("\nSo you need to pay %.2lf dollers", pay);
    return 0;
}