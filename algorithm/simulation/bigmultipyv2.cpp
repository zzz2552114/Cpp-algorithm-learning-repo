#include <bits/stdc++.h>
using namespace std;

string a, b;

vector<int> temp(1e4,0);

void multi(string a, int b,int j)
{
    int num = 0;
    int t = 0;
    int i = 0;
    for (; i < (int)a.size(); i++)
    {
        num = (a[i] - '0') * b + t;
        t = num / 10;
        num %= 10;
        temp[i+j]+=num;
        if(temp[i+j] >= 10){
            temp[i + j + 1] += temp[i + j] / 10;
            temp[i + j] %= 10;
        }
    }
    // 这里因为退出循环了，所以i已经 = size了
    if(t){
        temp[i + j] += t;
    }
}// 乘法逻辑，输入的是倒置的，输出的是倒置的


int main()
{
    cin >> a >> b;
    reverse(a.begin(), a.end());
    for (int i = 0; i < (int)b.size(); i++)
    {
        multi(a, (int)(b[(int)b.size() - i - 1] - '0'),i);

   }
   bool flag = true;
   for (auto it = temp.rbegin(); it != temp.rend(); it++)
   {
        if (*it == 0 && flag)
           continue;
        else
            flag = false;
        cout << *it;
   }
    cout << endl;
}