#include<bits/stdc++.h>
using namespace std;

int arr[200010][2];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q;i++){
        int x, y,cnt = 0;
        scanf("%d %d",&x,&y);
        for (int j = 1; j <= n;j++){
            if(x*arr[j][0]+arr[j][1]==y)
                cnt++;
        }
        cout << cnt << '\n';
    }
}