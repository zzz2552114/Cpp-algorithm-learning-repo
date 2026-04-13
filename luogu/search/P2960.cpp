#include <bits/stdc++.h>
using namespace std;
int mapx, mapy, mx, my;
struct node
{
    int x, y;
};
struct cntnode
{
    node n;
    int cnt;
};
int ans, checked[105][105];
vector<node> dir{{0,1}, {-1,0}, {0,-1}, {1,0}, {1,1}, {-1,1}, {-1,-1}, {1, -1}};
int main()
{
    cin >> mapx >> mapy >> mx >> my;
    cin.ignore();
    vector<string> arr(mapy);
    for (int i = mapy-1; i >= 0; i--)
    {
        getline(cin, arr[i]);
    } // 输入完成
    // 我打算用广搜
    queue<cntnode> q;
    q.push({{mx-1, my-1}, 0});
    while (!q.empty())
    {
        cntnode curr = q.front();
        q.pop();
        ans = max(ans, curr.cnt);
        cout << curr.n.x << ',' << curr.n.y << "  ans = " << ans <<'\n';
        for (int i = 0; i < 8; i++)
        {
            int newx = curr.n.x + dir[i].x;
            int newy = curr.n.y + dir[i].y;
            if (newx >= 0 && newx < mapx && newy >= 0 && newy < mapy && arr[newy][newx] != '*' && !checked[newy][newx])
            {
                checked[newy][newx] = 1;
                q.push({{newx, newy}, curr.cnt + 1});
            }
        }
    }
    cout << ans << endl;
}