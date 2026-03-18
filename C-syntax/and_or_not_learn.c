#include <stdio.h>

int main()
{
    int year;
    year = 1900;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("%d is special year", year);
    }
    else
    {
        printf("%d is not special year", year);
    }
    return 0;
}