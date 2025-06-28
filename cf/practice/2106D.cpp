#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    ll picked = 0;
    for(int i = 0, j = 0; i < n && j < m;){
        if(a[i] >= b[j]){
            picked += 1;
            i++;
            j++;
        }
        else i++;
    }

    if(picked == m){
        cout << 0 << '\n';
        return;
    }

    vector<ll> pfx(m + 1, INT_MAX), sfx(m + 1, INT_MIN);


    // pfx[j] = i <=> b[0, j) can be obtained with min index a[0, i)
    // sfx[j] = i <=> b[j, m) can be obtained with max index a[i, n)


    pfx[0] = 0;
    for(int j = 1, i = 1; j <= m && i <= n;){
        if(a[i - 1] >= b[j - 1]){
            pfx[j] = i;
            j++;
            i++;
        }
        else i++;
    }


    sfx[m] = n;

    for(int j = m - 1, i = n - 1; j >= 0 && i >= 0;){
        if(a[i] >= b[j]){
            sfx[j] = i;
            j--;
            i--;
        }
        else i--;
    }





    ll ans = LLONG_MAX;


    for(int j = 0; j < m; j++){
        if(pfx[j] <= sfx[j + 1]) ans = min(ans, b[j]);
    }

    if(ans == LLONG_MAX){
        cout << -1 << '\n';
        return;
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
