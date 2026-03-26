#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void pluss(string a,string b){
int t = 0;
for (int i = 0; i < (int)max(a.size(), b.size()); i++)
{
    int num = 0;
    if (i < (int)a.size())
    {
        num += a[i] - '0'; // ascii码字符型数字转数字语法！！！和迭代器相减出下标异曲同工
    }
    if (i < (int)b.size())
    {
        num += b[i] - '0';
    }
    num += t;
    ans.push_back(num % 10); // 对于一个可能是两位数可能是一位数的东西，取模得个位，除以10得十位
    t = num / 10;
}
if (t)
{
    ans.push_back(t);
}
}

int main(){
    // 用string存大数
    string a,b;
    cin >> a >> b;
    // 反转之后末尾对齐
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    pluss(a, b);
    reverse(ans.begin(), ans.end());
    for(int x:ans){
        cout << x ;
    }
    cout << endl;
}