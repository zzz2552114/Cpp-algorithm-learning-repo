#include <stdio.h>

int main()
{
    float float_1 = 11.27;
    float float_2 = 11.12345678910;
    printf("%f  %.10f\n", float_1, float_2);
    double double_1 = 11.12345678910;
    printf("%.10lf", double_1);
    return 0;
}