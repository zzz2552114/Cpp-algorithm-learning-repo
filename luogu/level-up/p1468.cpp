#include<bits/stdc++.h>
using namespace std;

bool flag = 1;
set<vector<int>> st;

vector<vector<int>> ans;
bool check(vector<int> &lamp, vector<int> & light, vector<int> &dark){
    if(st.count(lamp))
        return 0;
    for(int x:light){
        if(lamp[x]!=1)
            return 0;
    }
    for(int x:dark){
        if(lamp[x]) return 0;
    }
    st.insert(lamp);
    flag = 0;
    ans.push_back(lamp);
    return 1;
}

bool cmp(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == b[i])
            continue;
        return a[i] < b[i];
    }
    return 0;
}
int main()
{
    int n,c;
    cin >> n >> c;
    vector<int> light;
    int t;
    while(cin >> t,t!=-1) light.push_back(t-1);
    vector<int> dark;
    int td;
    while(cin >> td,td!=-1) dark.push_back(td-1);

    vector<int> lamp(n,1);
    // case1什么都不变
    if(dark.empty()){
        flag = 0;
        for (int i = 0; i < n;i++)
            cout << 1;
        cout << '\n';
    }
    if(c==0){
        if(flag) cout << "IMPOSSIBLE";
        return 0;
    }
    if(light.empty()){
        flag = 0;
        for (int i = 0; i < n;i++)
            cout << 0;
        cout << '\n';
    }
    vector<int> dif(n, 0);
    //case2，奇偶互变
    vector<int> odd(n), dob(n);
    for (int i = 0; i < n;i+=2){
        odd[i] = 1;
        if(i+1<n) dob[i+1] = 1;
    }
    // case3，3k+1互变
    vector<int> spec(n);
    for (int i = 0; i < n;i+=3) spec[i] = 1;


    vector<int> temp1(n);
    for (int i = 0; i < n;i++){
        temp1[i] = (lamp[i] ^ odd[i]);
    }
    check(temp1, light, dark);

    vector<int> temp2(n);
    for (int i = 0; i < n;i++)
        temp2[i] = (lamp[i] ^ dob[i]);
    check(temp2, light, dark);

    vector<int> temp3(n);
    for (int i = 0; i < n; i++)
        temp3[i] = (lamp[i] ^ spec[i]);
    check(temp3, light, dark);

    if(c == 1){
        if(flag)
            cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> temp4(n);
    for (int i = 0; i < n; i++)
        temp4[i] = (dif[i] ^ spec[i]);
    check(temp4, light, dark);

    vector<int> temp5(n);
    for (int i = 0; i < n; i++)
        temp5[i] = (temp1[i] ^ spec[i]);
    check(temp5, light, dark);

    vector<int> temp6(n);
    for (int i = 0; i < n; i++)
        temp6[i] = (temp2[i] ^ spec[i]);
    check(temp6, light, dark);
    if(flag)
        cout << "IMPOSSIBLE";

    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < (int)ans.size();i++){
        for (int j = 0; j < n;j++)
            cout << ans[i][j];
        cout << '\n';
    }
}

