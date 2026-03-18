#include <stdio.h>

int main()
{
    int category;
    float price;
    category = 1;
    price = 600.0;
    switch (category)
    {
    case 1:
        if (price < 500)
        {
            printf("The price is lower than the standerd of discount");
        }
        else if (500 <= price <= 1000)
        {
            printf("The electric item can get 5%% discount");
        }
        else
        {
            printf("The electric item can get 10percent discount");
        }
        break;
    case 2:
        if (price < 200)
        {
            printf("Cheap than discount");
        }
        else if (200 <= price <= 500)
        {
            printf("8percent discount");
        }
        else
        {
            printf("15percent discount");
        }
        break;
    }

    return 0;
}

// 这里打印%时候，要用到转义符%在正式%之前