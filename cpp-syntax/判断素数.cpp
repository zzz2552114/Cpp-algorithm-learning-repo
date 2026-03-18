#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int a;
    cout << "请输入一个整数" << endl;
    cin >> a;
    double sqrt_a = sqrt(a);
    bool flag = 1;
    for (int i = 2; i < sqrt_a; i++)
    {
        if (a % i == 0)
        {
            cout << a << "不是素数.  "<< a << " = " << i << " * " << a/i << endl;
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        cout << a << "是素数";
    }
}
