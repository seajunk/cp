#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll b[n];
    for(int i = 0; i < n; i++) cin >> b[i];


    ll s[m], t[m], w[m];
    vector<vector<vector<ll>>> children(n); // children[i] = {{child of i, cost for child to come to i}, {}, ...}

    ll mx = 0;
    for(int i = 0; i < m; i++){
        cin >> s[i] >> t[i] >> w[i];
        s[i]--; // 0-indexing
        t[i]--; // 0-indexing
        mx = max(mx, w[i]);
        children[t[i]].push_back({s[i], w[i]});
    }



    /*
       n nodes

       start with 0 batteries (i dont think charge matters)



       at ith node, can add up to b[i] more batteries


       can go from node s[j] to t[j] if we have atleast w[j] batteries



       what is min cost to get from node 0 to node n - 1 ?


       graph is a dag, so some form of post order dp?



       lets first calculate dp1[i]

       dp1[i] = minimum # of batteries we can start with st we can reach i without picking up any additional batteries




       binary search for "smallest k such that we can reach node n - 1 from node 0 by taking at most k batteries".

       then note that such smallest k is indeed the answer 
       (if we suppose otherwise, then there is a smaller l such that we can get from 0 to n - 1 by taking l batteries. obiviously this is a contradiction)

       so the problem reduces to confirming for some fixed k if its possible to reach
       n - 1 from 0 by taking at most k batteries.

       we can do this by some sort of dp + greedy

       maybe something like dp[i] = max number of batteries we can have after arriving at node i
    */



    // minimize k in [0, mx]
    ll lo = 0, hi = mx + 1;
    while(lo < hi){
        ll k = (hi - lo)/2 + lo;




        vector<ll> dp(n, LLONG_MIN); // dp[i] = max # of batteries we can have at node i
        vector<bool> seen(n, false);
        for(int i = 0; i < n; i++){
            if(seen[i]) continue;
            seen[i] = true;

            stack<ll> dfs;
            dfs.push(i);


            while(dfs.size()){
                ll top = dfs.top();
                bool finished = true;
                for(auto p : children[top]){
                    ll child = p[0];
                    ll cost = p[1];
                    if(!seen[child]) finished = false;
                }

                if(finished){
                    if(top == 0){
                        dp[top] = min(k, b[top]);

                        seen[top] = true;
                        dfs.pop();
                    }
                    else{
                        if(children[top].size() == 0){

                            seen[top] = true;
                            dfs.pop();
                        }
                        else{

                            ll mxchild = LLONG_MIN;
                            for(auto p : children[top]){
                                ll child = p[0];
                                ll cost = p[1];
                                if(dp[child] < cost) continue; // child cant afford to go to parents
                                mxchild = max(mxchild, dp[child]);
                            }
                            if(mxchild != LLONG_MIN) dp[top] = min(k, mxchild + b[top]);

                            seen[top] = true;
                            dfs.pop();
                        }
                    }
                }
                else{
                    for(auto p : children[top]){
                        ll child = p[0];
                        if(!seen[child]) dfs.push(child);
                    }
                }
            }
        }


        bool works = dp[n - 1] != LLONG_MIN;

        if(works) hi = k;
        else lo = k + 1;
    }


    if(lo == mx + 1) cout << -1 << '\n';
    else cout << lo << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
