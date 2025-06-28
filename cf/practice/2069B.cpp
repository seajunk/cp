#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n][m];

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++) cin >> a[r][c]; 
    }

    map<ll, set<pair<ll, ll>>> ss; // (colour, set of taken cells of colour)
    set<ll> extra; // set of colours that need two stranger sets to cover


    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < m; c++){
            if(ss[a[r][c]].find({r, c}) != ss[a[r][c]].end()){
                extra.insert(a[r][c]); // colour a[r][c] needs two stranger sets
            }

            ss[a[r][c]].insert({r, min(m - 1, c + 1)});
            ss[a[r][c]].insert({r, max(0ll, c - 1)});
            ss[a[r][c]].insert({max(0ll, r - 1), c});
            ss[a[r][c]].insert({min(n - 1, r + 1), c});
        }
    }


    ll ans = ss.size() + extra.size() - (extra.size() > 0 ? 2 : 1);

    cout << ans << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
