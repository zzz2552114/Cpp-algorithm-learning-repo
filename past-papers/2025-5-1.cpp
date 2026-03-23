#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    string s0;
    /* 
    先写思路
    while循环+pos遍历整个列表，在里面嵌套for循环判断相等，空格最后统一加
    */
    int pos = 0;
    int size = (int)s.size();
    int count = 0;
    while(pos < size){
        count = 0;
        for (int i = pos; i < size;i++){
            if(s[i] != s[i+1]){//这里只有可能越界1，会弹出\0，不会报错
                count = i - pos + 1;
                pos = i + 1;
                s0 += s[i];
                if(count >1){
                string num = to_string(count);
                s0 += num;
                }
                break;
            }
        }
    }
    string ans;
    for(char x :s0){
        ans.push_back(x);
        ans.push_back(' ');
    }
    ans.pop_back();
    cout << ans << endl;
}