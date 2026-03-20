#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "输入字符串s:" << endl;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (!isalpha((unsigned char)s[i])){
            // 这里判断是不是字母，用isalpha,里面转换成正数数字
            s.erase(i, 1);
            i -= 1;
            // 这里有一个坑，要小心i的下标变化
        }
        else
        {
            s[i] = tolower(s[i]);
        }
    }
    string s_reverse = s;
    reverse(s_reverse.begin(), s_reverse.end());
    cout << s << endl;      
    if (s == s_reverse)
    {
        cout << "s是回文字符串" << endl;
    }
}