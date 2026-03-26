#include <bits/stdc++.h>
using namespace std;
int main(){
    // 对于一个数组，先遍历找最小值，放到首位，逐渐-1遍历长度即可
    vector<int> arr;
    for (int i = 0;i<4;i++){
        int n;
        cin >> n;
        arr.push_back(n); // 3,2,1
    }
    int t = 0;
    while(t<arr.size()){
        int minpos = t;
        for (int i = t; i < arr.size(); i++)
        {
            if (arr[i] < arr[minpos]){
                // 这里不要先交换，否则会增加n的空间复杂度，再乘次数就是n^2的空间复杂度
                // 如果先交换了，就可以看作一个冒泡排序了
                // 用下标记录最后交换
                // int temp = arr[t];
                // arr[t] = arr[i];
                // arr[i] = temp;
                minpos = i;
            }
        }
        // for循环结束之后再换
        int temp = arr[t];
        arr[t] = arr[minpos];
        arr[minpos] = temp;
        t++;
    }
    for (int x:arr){
        cout << x << ' ';
    }
    cout << endl;
}