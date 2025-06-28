#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll n, ll k){
    return (n % k + k) % k;
}

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> children(n);
    vector<ll> parent(n);

    for(int i = 1; i < n; i++){
        ll p; cin >> p; p--;
        children[p].push_back(i);
        parent[i] = p;
    }

    ll MOD = 998244353;

    /*
       dp[i] = number of valid sequences that end at node i 
       then transition is 

       dp[i] = prod(dp[j] : j is one layer above i and j isnt i's parent)

       we can efficiently compute this by first getting prod(dp[j] : j is one layer above i) then dividing out this product by parent of dp[i]. 

       then we can compute dp for each i without needing to iterate over all guys in upper layer each time

       might have to do some funky Z/pZ inverse finding shenangians
    */


    ll dp[n];

    dp[0] = 1;

    queue<ll> bfs;
    bfs.push(0);

    while(bfs.size()){

        // guys in curr have dp initialized
        // guys in next dont
        vector<ll> curr, nxt;

        // fill curr
        while(bfs.size()){
            curr.push_back(bfs.front());
            bfs.pop();
        }

        // get product of curr, fill nxt
        ll sum = 0; // product of all guys in curr
        for(auto node : curr){
            sum += dp[node];
            sum = mod(sum, MOD);
            for(ll child : children[node]){
                nxt.push_back(child);
                bfs.push(child);
            }
        }

        for(auto node : nxt){
            if(parent[node] == 0) dp[node] = sum;
            else dp[node] = sum - dp[parent[node]];
            dp[node] = mod(dp[node], MOD);
        }
    }



    ll ans  = 0;
    for(int i = 0; i < n; i++){
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
