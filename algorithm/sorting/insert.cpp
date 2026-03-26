#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    for (int i = 0; i < 5;i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    // 插入排序
    // 先分两堆，左有序右无序
    int size = (int)arr.size();
    for (int i = 1;i<size;i++){
        int temp = arr[i];
        int t = i - 1;
        while (t >= 0){
            if (arr[t]>temp){
                arr[t + 1] = arr[t];
                // 不断把比他大的往右推，空出他的位置，位置就是比它小的第一个的右边一个
            }else{
                break; // 注意这里找到比他小的就就退出了，不会执行t--;
            }
            t--;
        }
        arr[t + 1] = temp;
    }
    for(int x:arr){
        cout << x << ' ';
    }
    cout << endl;
}
// shell希尔排序就是先分组插入排序，不想写了，没用