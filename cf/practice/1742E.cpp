#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, q; cin >> n >> q;
    ll a[n];
    for(int i = 0; i < n ;i++) cin >> a[i];

    vector<ll> pfmx(n);
    pfmx[0] = a[0];
    for(int i = 1; i < n; i++) pfmx[i] = max(pfmx[i - 1], a[i]);

    vector<ll> pfs(n + 1);
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + a[i - 1];


    for(int i = 0; i < q; i++){
        ll k; cin >> k;

        // find largest i st pfmx[i] <= k
        ll lo = -1, hi = n - 1; 
        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;
            if(pfmx[mid] <= k) lo = mid;
            else hi = mid - 1;
        }
        cout << pfs[lo + 1] << ' ';
    }
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
