#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
using namespace std;

struct node
{
    int x, y;
};
int n, m, x_0, y_0;
int check[400 * 401];
vector<node> dir{{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
queue<node> q;
int main(){
    cin >> n >> m >> x_0 >> y_0;
    int ans[n][m];
    memset(ans, -1, sizeof(ans));
    q.push({x_0, y_0});
    check[x_0 + y_0 * 400] = 1;
    ans[x_0 - 1][y_0 - 1] = 0;

    while(!q.empty()){
        node now = q.front();
        q.pop();
        for (int i = 0; i < 8;i++){
            int nx = now.x + dir[i].x;
            int ny = now.y + dir[i].y;
            if(nx>=1 && nx<=n && ny >=1 && ny <=m && !check[nx + ny*400]){
                q.push({nx, ny});
                check[nx+ny*400] = 1;
                ans[nx - 1][ny - 1] = ans[now.x-1][now.y-1] + 1;
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}