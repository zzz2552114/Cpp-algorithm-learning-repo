#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<long long> prq;
    priority_queue<int,vector<int>,greater<int>> prq2; // 另外一种降低空间复杂度的方法，从小到大排序
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        prq.emplace(t);

        // prq2
        if(prq2.size()<k)
        {
            prq2.push(t);
        }else
        {
            if(t > prq2.top()){
                prq2.pop();
                prq2.emplace(t);
            }
        }
    }

    for (int i = 0; i < k;i++)
    {
        cout << prq.top() << ' ';
        prq.pop();
    }
    cout << endl;

    vector<int> vec(k);
    int i = 0;
    while(!prq2.empty())
    {
        vec[i] = prq2.top();
        prq2.pop();
        i++;
    }
    for (auto it = vec.rbegin(); it != vec.rend();it++){
        cout << *it << ' ';
    }
    cout << endl;
}