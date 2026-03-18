#include <stdio.h>
#include<math.h>

int main()
{
    int a, b, c;
    double answer1,answer2;
    a = 2;
    b = -6;
    c = 4;
    answer1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    answer2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    printf("the 2 answers are : %lf and %lf", answer1, answer2);
    return 0;
}