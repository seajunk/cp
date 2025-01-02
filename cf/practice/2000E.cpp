#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    ll w; cin >> w;
    ll a[w];
    for(int i = 0; i < w; i++) cin >> a[i];


    vector<ll> weight;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            ll lbr, ubr, lbc, ubc;
            lbr = max(0ll, r - (k - 1)); 
            ubr = min(n - 1, r + (k - 1)); 
            lbc = max(0ll, c - (k - 1)); 
            ubc = min(m - 1, c + (k - 1)); 

            ll count = (1 + (ubr - lbr + 1) - k) * (1 + (ubc - lbc + 1) - k);
            vector<ll> in = {r, c};

            weight.push_back(count);
        }
    }
    
    ll ans = 0;
    sort(weight.begin(), weight.end(), [](ll l, ll r){return l > r;});
    sort(a, a + w, [](ll l, ll r){return l > r;});
    for(int i = 0; i < w; i++){
        ans += a[i] * weight[i];
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


