#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxPathSum(TreeNode* root) {


    int n = 0;
    map<int, vector<int>> children;
    map<int, int> value;



    function<void(TreeNode*)> temp = [&](TreeNode* node){
        int curr = n;
        value[n] = node->val;
        if(node->left != NULL){
            children[curr].push_back(n + 1);
            n++;
            temp(node->left);
        }
        if(node->right != NULL){
            children[curr].push_back(n + 1);
            n++;
            temp(node->right);
        }
    };
    temp(root);
    n++;

    vector<bool> seen(n, false);
    vector<int> dp1(n); // dp1[i] = max sum path from i to leaf 
    vector<int> dp2(n); // dp2[i] = max sum path in tree rooted at i

    stack<int> dfs;

    seen[0] = true;
    dfs.push(0);

    while(dfs.size()){
        int top = dfs.top();
        bool finished = true;

        int mx = -10000;
        for(int child : children[top]){
            if(!seen[child]){
                finished = false;
                dfs.push(child);
                continue;
            }
            mx = max(mx, dp1[child]);
        }


        if(finished){
            dp1[top] = max(value[top], value[top] + mx);
            dfs.pop();
            seen[top] = true;
        }
    }

    seen.assign(n, false);

    seen[0] = true;
    dfs.push(0);

    while(dfs.size()){
        int top = dfs.top();
        bool finished = true;

        int sumdp1 = value[top];
        int mxdp2 = -10000;
        for(int child : children[top]){
            if(!seen[child]){
                finished = false;
                dfs.push(child);
                continue;
            }
            mxdp2 = max(mxdp2, dp2[child]);
            sumdp1 = max(sumdp1, sumdp1 + dp1[child]);
        }


        if(finished){
            seen[top] = true;
            dfs.pop();
            dp2[top] = max(mxdp2, sumdp1);
        }
    }





    cout << dp2[0] << '\n';
    return dp2[0];
}
