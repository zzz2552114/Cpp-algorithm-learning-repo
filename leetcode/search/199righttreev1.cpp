#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    struct node
    {
        TreeNode *t;
        int cnt;
    };
    vector<int> rightSideView(TreeNode *root)
    {
        // 先来个bfs版本
        if (!root)
            return {};
        int cntarr[100];
        vector<int> ans;
        memset(cntarr, 0, sizeof(cntarr));
        queue<node> q;
        q.push({root, 1});
        while (!q.empty())
        {
            node now = q.front();
            if (!cntarr[now.cnt])
            {
                ans.push_back(now.t->val);
                cntarr[now.cnt] = 1;
            }
            q.pop();
            if (now.t->right)
                q.push({now.t->right, now.cnt + 1});
            if (now.t->left)
                q.push({now.t->left, now.cnt + 1});
        }
        return ans;
    }
};