#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct datas{
	int node,w;
};
const int inf = 1e9;
bool cmp(const datas& a,const datas& b){
	return a.w > b.w;
}
int main(){
	int n,m,st;
	cin >> n >> m >> st;
	vector<vector<datas>> vec(n+1);
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		datas t;t.node = v;t.w = w;
		vec[u].push_back(t);
	}
	priority_queue<datas,vector<datas>,decltype(&cmp)> prq(cmp);
	vector<int> vis(n+1,0);
	vector<int> dis(n+1,inf);
	datas s;s.node = 1;s.w = 0;
	prq.push(s);
	while(!prq.empty()){
		datas curr = prq.top();prq.pop();
		int cn = curr.node,cw = curr.w;
		if(vis[cn]) continue;
		vis[cn] = 1;
		dis[cn] = cw;
		for(int i = 0;i<(int)vec[cn].size();i++){
			datas temp;temp.node = vec[cn][i].node;temp.w = vec[cn][i].w+cw;
			prq.push(temp);
		}
	}
	for(int i = 1;i<=n;i++) cout << dis[i] << ' ';
}