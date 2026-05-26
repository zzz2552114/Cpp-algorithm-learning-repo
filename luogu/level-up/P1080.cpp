#include<bits/stdc++.h>
using namespace std;
struct datas{
    double l, r;
};
int n;
vector<datas> arr(1005);
vector<double> prefix(1005);
bool cmp(datas& a,datas& b){
    if(a.l == b.l) return a.r<b.r;
    return a.l < b.l;
}
bool check(long long mid)
{
    vector<datas> arrt = arr;
    vector<double> prefixt = prefix;
    int st = 1;
    for (int i = 1; i <= n;){
        int k = i;
        datas curr = arrt[i];
        while((long long)prefixt[k-1]/curr.r>mid){
            if(k<=st) return 0;
            k--;
            datas temp = arrt[k];
            arrt[k] = curr;
            arrt[k + 1] = temp;
            prefixt[k] = prefixt[k] / temp.l * curr.l;
            st = k+1;
        }
        i = k+1;
    }
    return 1;
}
int main(){
    cin >> n;
    for (int i = 0; i <= n;i++){
        cin >> arr[i].l >> arr[i].r;
    }
    sort(arr.begin() + 1, arr.begin() + n + 1, cmp);
    prefix[0] = arr[0].l;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[0] * arr[i].l;
    }
    long long l = 0, r = 1e13;
    while(l<r){
        long long mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l;
}