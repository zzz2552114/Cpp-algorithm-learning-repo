#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1;
    string s2;
    string s3;
    cout << "input 2 strings and a position:" << endl;
    getline(cin, s1);
    getline(cin, s2);
    int pos;
    cin >> pos;
    if(pos > s1.length()){
        cout << "Invalid pos" << endl;
        return 1;
    }else{
        s3 = s1.insert(pos, s2);
        // 这里新学到了一个insert的方法，它的第一个参数是位置，第二个参数是要插入的字符串
        // pos表示插入的位置，s2表示要插入的字符串，那么s1在这个位置就会插入s2，原来pos位置以及之后的字符会往后移动（pos是s2的首个字符的下标）
        // 这个方法会直接修改s1，并且返回修改后的s1，所以我们可以直接把它赋值给s3
    }
    s3 = "START" + s3 + "END";
    cout << s3 << endl;
}