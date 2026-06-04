#include<bits/stdc++.h>
using namespace std;
vector<int> arr,cf,tr;
int n, m;
int lowbit(int x){
	return x & -x;
}

void add(int i,long long x){
	while(i<=n){
		tr[i] += x;
		i += lowbit(i);
	}
}
int query(int i){
	long long res = 0;
	while(i>0){
		res += tr[i];
		i -= lowbit(i);
	}
	return res;
}
int main()
{
	cin >> n >> m;
	arr.resize(500010);
	cf.resize(500010);
	tr.assign(500010, 0);
	for (int i = 1; i <= n;i++){
		cin >> arr[i];
		cf[i] = arr[i] - arr[i - 1];
		add(i, cf[i]);
	}
	while (m--)
	{
		int f;
		cin >> f;
		if (f == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			add(x, k);
			add(y+1, -k);
		}
		else if (f == 2)
		{
			int x;
			cin >> x;
			cout << query(x) << '\n';
		}
	}
}
