#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // a[u] - a[v] >= b[u] - b[v] iff u to v edge exists
    // a[u] - b[u] >= a[v] - b[v]

    vector<vector<ll>> c(n, vector<ll>(2));
    for(int i = 0; i < n; i++){
        c[i][1] = a[i] - b[i];
        c[i][0] = i;
    }

    sort(c.begin(), c.end(), [](auto l, auto r){ return l[1] < r[1];}); 

    set<ll> ans;

    ll mx = LLONG_MIN;
    for(int i = 0; i < n; i++) mx = max(mx, c[i][1]);
    for(int i = 0; i < n; i++){
        if(c[i][1] == mx) ans.insert(c[i][0]);
    }

    cout << ans.size() << '\n';
    for(ll e : ans) cout << e + 1 << ' ';
    cout << '\n';


    


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
