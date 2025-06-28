#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
        if(a[i] == n) a[i]--;
    }

    sort(a, a + m);
    ll sfs[m + 1];
    sfs[m] = 0;
    for(int i = m - 1; i >= 0; i--) sfs[i] = sfs[i + 1] + a[i];

    // paint a, b -> if a + b >= n, min(a, b, n - 1) * 2 else 0

    ll ans = 0;
    for(int i = 0; i < m; i++){
        // want smallest i < j such that a[i] + a[j] >= n

        ll lo = i + 1, hi = m;
        while(lo < hi){
            ll j = (hi - lo)/2 + lo;
            if(a[i] + a[j] >= n) hi = j;
            else lo = j + 1;
        }
        if(lo != m){
            ans += 2*(sfs[lo] + a[i] * (m - lo) - (n - 1)*(m - lo)); 
            //cout << (2*(sfs[lo] + a[i] * (m - lo) - (n - 1)*(m - lo))) << '\n';
        }
    }
    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
