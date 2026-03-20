#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    char del;
    getline(cin,s);
    cin >> del;

    size_t pos = 0;
    size_t next_pos;

    // 选用while循环的话必须要想明白逻辑和特殊情况
    while((next_pos = s.find(del,pos)) != string::npos){
        string output = s.substr(pos, next_pos - pos);
        if(!output.empty()){
            cout << output << endl;
        }
        pos = next_pos + 1;
    }
    string output = s.substr(pos);
    // 这里只传一个参数默认取到最后
    // 默认当索引 = size（即刚好越界1个）的时候返回空字符串
    if(! output.empty()){
        cout << output << endl;
    }
}