#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    // 操作次数
    vector<int> arr;
    vector<pair<string, int>> func(m);
    for (int i = 0; i < m;i++)
    {
        cin >> func[i].first >> func[i].second;
    }
    for (int i=0;i<m;i++)
    {
        string order = func[i].first;
        auto up_pos = upper_bound(arr.begin(), arr.end(), func[i].second);
        auto low_pos = lower_bound(arr.begin(), arr.end(), func[i].second);
        if ( order == "insert")
        {   
            arr.insert(up_pos, func[i].second);
        }else if(order == "delete")
        {
            // vector本身没有查找，但是我维护的是有序的，所以二分查找反而更好
            if(*low_pos == func[i].second)
            {
                arr.erase(low_pos);
            }
        }else if( order == "count")
        {
            cout << (up_pos - low_pos) << endl;
        }else
        {
                vector<int> arr1 = arr;
                arr1.erase(unique(arr1.begin(), arr1.end()),arr1.end());
                int size = (int)arr1.size();
                if(func[i].second <= size)
                {
                    cout << arr1[func[i].second - 1] << endl;
                }
        }
    }
}