#include <iostream>

using namespace std;

int main()
{
    int M;
    int N;
    cout << "请输入总头数:";
    cin >> M;
    cout << "请输入总脚数:";
    cin >> N;
    if (N % 2 == 1)
    {
        cout << "数据错：总脚数N必须是偶数" << endl;
        return 1;
    }
    int y = N / 2 - M;
    int x = M - y;
    if (x < 0 || y < 0)
    {
        cout << "求出的头数不能为负数" << endl;
        return 1;
    }
    cout << "鸡:" << x << endl;
    cout << "兔:" << y << endl;
    return 0;
}