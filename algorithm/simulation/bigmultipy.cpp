#include <bits/stdc++.h>
using namespace std;

string a, b;
int num;

void multi(vector<vector<int>>& temp,string a,int b,int i){
    int t = 0;
    reverse(a.begin(), a.end());
    for (char x :a){
        num = (x - '0') * b + t;
        t = num / 10;
        num %= 10;
        temp[i].push_back(num);
    }
    if(t){
        temp[i].push_back(t);
    }

}
vector<int> pluss(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < (int)max(a.size(), b.size()); i++)
    {
        int num = 0;
        if (i < (int)a.size())
        {
            num += a[i]; 
        }
        if (i < (int)b.size())
        {
            num += b[i];
        }
        num += t;
        ans.push_back(num % 10); // 对于一个可能是两位数可能是一位数的东西，取模得个位，除以10得十位
        t = num / 10;
    }
    if (t)
    {
        ans.push_back(t);
    }
    return ans;
}
int main(){
    cin >> a >> b;
    vector<vector<int>> temp((int)b.size());
    
    for (int i = 0;i<(int)b.size();i++)
    {
        multi(temp,a, (int)(b[(int)b.size()-i-1] - '0'),i);
    }
    vector<int> sum = temp[0];
    for (int i = 0; i < (int)(b.size() - 1); i++)
    {
        for (int j = 0; j <= i;j++){
            temp[i + 1].insert(temp[i + 1].begin(), 0);
        }
        sum = pluss(sum, temp[i + 1]);
    }
    for (auto it = sum.rbegin(); it != sum.rend();it++)
    {
        cout << *it;
    }
    cout << endl;
}