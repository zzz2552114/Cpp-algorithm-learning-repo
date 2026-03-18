#include <stdio.h>

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        if (i % 3 == 0)
        {
            continue;
        }
        else if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
        if (i > 40)
        {
            break;
        }
    }
}