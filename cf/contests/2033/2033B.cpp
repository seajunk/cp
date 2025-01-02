#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n][n];
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++) cin >> a[r][c];
    }

    vector<ll> mn(2*n - 1, 0);

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            ll idx = r - c + n - 1;
            mn[idx] = min(mn[idx], a[r][c]);
        }
    }

    ll ans = 0;
    for(ll e : mn){
        if(e < 0) ans += e * -1;
    }

    cout << ans << '\n';


    


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
