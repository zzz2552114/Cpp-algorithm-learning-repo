#include <stdio.h>

int main()
{
    char name[20];
    int n;
    printf("input how many people you wanna greet : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("input the name who you wanna greet:");
        scanf("%20s", name);
        printf("what you greet to %s is : \n\"hi,%s!\"\n\n\n\n", name, name);
    }
    printf("you've great to everyone successfully!");
}