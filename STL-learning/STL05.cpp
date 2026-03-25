#include <bits/stdc++.h>
using namespace std;
// 这个题我想写3种实现
// 1.pair 2.struct 3.map
bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

struct Student{
    string name;
    int score;
};
bool cmp2(Student& a,Student& b){
    if (a.score != b.score){
        return a.score > b.score;
    }
    return a.name < b.name;
}


int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> vec(n);
    vector<Student> vec2(n); // struct
    // map<string, int> mp; // map 这里有个问题，map只能按键排序，不能按值，那只能手动写排序？算了。。。
    for(int i = 0;i < n; i++){
        cin >> vec[i].first >> vec[i].second;
        vec2[i].name = vec[i].first;
        vec2[i].score = vec[i].second; // struct
        // mp[vec[i].first] = vec[i].second;// map
        }
    sort(vec.begin(), vec.end(), cmp);
    sort(vec2.begin(), vec2.end(),cmp2);
    for (pair<string, int> x:vec)
    {
        cout << x.first << ' ' << x.second << '\n';
    }
    cout << endl;
    for (Student x: vec2){
        cout << x.name << ' ' << x.score << '\n';
    }
    cout << endl;


}