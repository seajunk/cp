#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> c(m, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> c[j][i]; 
    }

    vector<vector<ll>> pfs(m, vector<ll>(n + 1));

    for(int i = 0; i < m; i++) sort(c[i].begin(), c[i].end());
    for(int i = 0; i < m; i++) pfs[i][0] = 0;
    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++) pfs[i][j] = pfs[i][j - 1] + c[i][j - 1];
    }

    ll ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ans += c[i][j] * (j + 1) - pfs[i][j + 1];
        }
    }
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
