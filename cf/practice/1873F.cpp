#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n], h[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> h[i];

    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + a[i - 1];


    // sliding window / binary search

    ll lo = 1, hi = n + 1; // search on [1, n]

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        ll valid = false;


        if(n == 1){
            if(a[0] <= k) valid = true;
        }
        else{
            ll len = 1;
            for(int i = 1; i < n; i++){

                // prev
                if(len == mid){
                    if(pfs[i] - pfs[i - len] <= k) valid = true;
                }

                if(h[i - 1] % h[i] != 0){
                    len = 1;
                }
                else{
                    len = min(len + 1, mid);
                }

                if(len == mid){
                    if(pfs[i + 1] - pfs[i + 1 - len] <= k) valid = true;
                }
            }
        }

        if(valid) lo = mid + 1;
        else hi = mid;
    }

    cout << hi - 1 << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
