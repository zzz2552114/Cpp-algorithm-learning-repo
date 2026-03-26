#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    // 再开辟一个数组，用来当作计数！和map映射一样。
    // 新计数容器的下标是内容，值是次数，可以用 cnt[val]++作为遍历结果
    // 如果内容值很大，因为数组是连续内存，所以空间开销很大，选unordered_map
    // 如果内容值正常，数组的访问和修改效率高，选数组
    // 实际上可以把计数数组的范围压缩到 max - min + 1，把min偏移成0，剩下的都偏移一个常数即可
    int max_pos = 0;
    int min_pos = 0;
    for (int i = 0; i < n;i++){
        if(arr[i] > arr[max_pos]){
            max_pos = i;
        }
        if(arr[i] < arr[min_pos]){
            min_pos = i;
        }
    }
    int range = arr[max_pos] - arr[min_pos] + 1;
    int min = arr[min_pos];
    vector<int> cnt(range);
    // 从这里要记住！！！是对原数组遍历！！同时计数！！！核心就这一行代码
    for (int i = 0; i < n;i++){
        cnt[arr[i]-min]++;
    }
    // 遍历cnt输出即可
    for (int i = 0; i < range;i++){
        if(cnt[i]!=0){
            for (int j = 0; j < cnt[i];j++){
                cout << i+min << ' ';
                // 注意这里是遍历次数，但是要输出元素(下标)
            }
        }
    }
}