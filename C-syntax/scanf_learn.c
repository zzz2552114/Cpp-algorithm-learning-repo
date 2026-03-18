#include <stdio.h>

int main()
{
    char category;
    float price;
    printf("input the category(A/B) and the price:");
    scanf("%c %f", &category, &price);
    switch (category)
    {
    case 'A':
        if (price < 500)
        {
            printf("The price is lower than the standerd of discount");
        }
        else if (price <= 1000)
        {
            printf("The electric item can get 5%% discount");
        }
        else
        {
            printf("The electric item can get 10%% discount");
        }
        break;
    case 'B':
        if (price < 200)
        {
            printf("Cheap than discount");
        }
        else if (price <= 500)
        {
            printf("8%% discount");
        }
        else
        {
            printf("15%% discount");
        }
        break;
    default:
        printf("You've put the wrong category of item");
    }

    return 0;
}