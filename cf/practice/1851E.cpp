#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    for(int i = 0; i < k; i++){
        ll in; cin >> in;
        c[in - 1] = 0; // infinite supply is equivalent to costing 0 (?)
    }

    vector<vector<ll>> children(n);
    // isnt this O(n^2) ?
    for(int i = 0; i < n; i++){
        ll m; cin >> m;
        for(int j = 0; j < m; j++){
            ll in; cin >> in;
            children[i].push_back(in - 1);
        }
    }


    /*
       c[i] = cost of potion i
       children[i] = array of potions needed to make i

       n <= 1e5


       need to find min cost to make potion i for every i



       "no potion can be obtained from itself through one or more mixing processes"
       what that mean ?


       lets try graph approach, 
       graph is directed, 
       each i is node, 
       edge (i -> j) exists if j needs i in formula

       then no loop exists ? since no potion can be obtained from itself through mixing process.

       so graph is dag, so post order dfs works


       so dp on dag where min cost is min(c[i], sum of min cost of formula for i)
    */





    vector<ll> mn(n, LLONG_MAX);



    vector<bool> seen(n, false);

    for(int i = 0; i < n; i++){
        if(seen[i]) continue;


        stack<ll> dfs;
        dfs.push(i);

        while(dfs.size()){
            bool finished = true;

            for(auto child : children[dfs.top()]){
                if(!seen[child]){
                    finished = false;
                    dfs.push(child);
                }
            }

            if(finished){
                ll top = dfs.top();
                dfs.pop();
                seen[top] = true;

                mn[top] = c[top];

                if(children[top].size() > 0){
                    ll price = 0;

                    for(auto child : children[top]) price += mn[child];
                    mn[top] = min(mn[top], price);
                }
            }
        }
    }


    for(int i = 0; i < n; i++) cout << mn[i] << ' ';
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
