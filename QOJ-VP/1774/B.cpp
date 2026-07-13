#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    int s = a.first,t = b.first;
    if(a.first == -1) s = a.second;
    if(b.first == -1) t = b.second;
    return s < t;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {   
        bool f = 0;
        vector<pair<int,int>> datas;
        int n;
        int g;
        cin >> n >> g;
        int glue = 0;
        for(int i = 1;i<=n;i++)
        {
            int x,y;
            cin >> x >> y;
            if(x>y && y!=-1){
                cout << "NIE" << '\n';
                f = 1;
            }
            if(x==-1 && y==-1)
            {
                glue++;
                continue;
            }
            datas.push_back({x,y});
        }
        if (f)
            continue;
        sort(datas.begin(),datas.end(),cmp);
        int len = (int)datas.size();
        int temp = 0,down=0,up = 0;
        bool flag = 1;

        for(int i = 0;i<len;i++)
        {
            int st = datas[i].first, ed = datas[i].second;
            if(st==-1){
                up += ed-temp-1;
                if(temp >= ed){
                    cout << "NIE" << '\n';
                    flag = 0;
                    break;
                }
                temp = ed;
            }
            else{
                if(temp >= st ){
                    cout << "NIE" << '\n';
                    flag = 0;
                    break;
                }
                if(st!=temp+1) up++,down++;
                if(ed == -1){
                    temp = st; 
                    if(i<len-1){
                        if(datas[i+1].first!=-1) up += datas[i+1].first-st-1;
                    }
                    else {
                        up += g-st-1;
                    }
                }
                else temp = ed;
            }
        }
        if (!flag)
            continue;
        if (temp != g)
            up++, down++;
        if (down <= glue && glue <= up)
            cout << "TAK" << '\n';
        else
            cout << "NIE" <<'\n';
    }
}
