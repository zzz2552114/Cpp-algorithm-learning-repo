#include <bits/stdc++.h>
using namespace std;
// 先写逻辑，跳转逻辑，两个分隔符之间的夹逼
// 注意语法
int main(){
    string s;
    char del;
    getline(cin,s);
    cin >> del;

    for (int i = 0; i < s.size();i++){
        // 先看分隔符在不在s的剩余里
        if(s.find(del,i) != string::npos){
            // 这里就是还在，直接夹逼，但是还是要先考虑初始情况
            if(i < s.find(del) && s.find(del) != 0){
                string s0 = s.substr(0, s.find(del));
                cout << s0 << endl;
                // 跳转逻辑从这里开始：i跳转到find的前一个，这样的话i++就会刚好加到find
                i = s.find(del) - 1;
                continue;
            }
            // 但是还要考虑后面没有的情况，先写！
            else if(s.find(del,i+1) == string::npos){
                if(s.find(del,i) == s.size()-1){
                    break;
                }
                // 这里表示后面没有分隔符了，整体打印
                string s0 = s.substr(i + 1, s.size() - i -1);
                cout << s0 << endl;
                break;
            }else{
                if (s.find(del, i + 1) - i - 1 == 0){
                    continue;
                }
                    // 终于可以开始夹逼逻辑了
                    string
                    s0 = s.substr(i + 1, s.find(del, i + 1) - i - 1);
                // 先处理空字符串

                cout << s0 << endl;
                i = s.find(del, i + 1) - 1;
            }
        }else if(s.find(del) == 0){
            // 处理初始情况里del在第一位的情况
            continue;
        }else{
            cout << s << endl;
            break;
        }
    }
}