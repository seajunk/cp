#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums, int k, int limit) {
    int n = nums.size();

    // dp[i] = set of values u can get from using ith value as the first vaule in the subsequence
    // dp[i] = {nums[i] - guy : j in [0, i) guy in dp[j]} 

    vector<set<pair<int, int>>> dp(n);

    dp[n - 1] = {{nums[n - 1], nums[n - 1]}};



    // scuffed beyond comprehension
    // this is terrible

    vector<int> ans;
    for(int i = n - 2; i >= 0; i--){
        dp[i].insert({nums[i], nums[i]});
        if(nums[i] == k && nums[i] <= limit) ans.push_back(nums[i]);
        for(int j = i + 1; j < n; j++){

            // O(2^n) ?
            for(auto guy : dp[j]){
                if(guy.second * nums[i] <= limit){
                    dp[i].insert({nums[i] - guy.first, guy.second * nums[i]});
                    if(nums[i] - guy.first == k) ans.push_back(guy.second * nums[i]);
                }
                //else dp[i].insert({nums[i] - guy.first, limit + 1});



            }
        }

    }

    if(nums[n - 1] == k && nums[n - 1] <= limit) ans.push_back(nums[n - 1]);

    if(ans.size() == 0) return -1;
    else{
        int mx = -1;
        for(auto e : ans) mx = max(mx, e);
        return mx;
    }
}

int main(){
    vector<int> nums = {0, 3, 4, 8};
    int k = -7;
    int limit = 20;
    maxProduct(nums, k, limit);


}
