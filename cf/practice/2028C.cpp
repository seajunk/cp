#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, v; cin >> n >> m >> v;
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll pfcnt[n + 1]; // pfcnt[i] = # of tasty sections if alices cake starts from index i
    // ie # of guys that fit in [0, i)


    ll sfcnt[n + 1]; // sfcnt[i] # of tasy sections of alices cake ends at index i
    // ie # of guys that fit in [i, n)

    pfcnt[0] = 0;
    ll curr = 0;
    for(ll i = 1; i <= n; i++){
        curr += a[i - 1];

        if(curr >= v){
            pfcnt[i] = pfcnt[i - 1] + 1;
            curr = 0;
        }
        else{
            pfcnt[i] = pfcnt[i - 1];
        }
    }

    sfcnt[n] = 0;
    curr = 0;
    for(ll i = n - 1; i >= 0; i--){
        curr += a[i];

        if(curr >= v){
            sfcnt[i] = sfcnt[i + 1] + 1;
            curr = 0;
        }
        else{
            sfcnt[i] = sfcnt[i + 1];
        }
    }

    ll pfs[n + 1];
    pfs[0] = 0;
    for(ll i = 1; i <= n; i++){
        pfs[i] = pfs[i - 1] + a[i - 1];
    }

    ll ans = -1;
    for(ll l = 0; l < n; l++){
        // alics cake [l, r)
        // bin search for r
        ll left = pfcnt[l];

        // want largest r such that left + right >= m
        if(left + sfcnt[n] >= m){
            ans = max(ans,pfs[n] - pfs[l]);
            continue;
        }                

        ll lo = l, hi = n;

        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;

            if(left + sfcnt[mid] >= m){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }

        }
        lo--;
        if(lo == -1) continue;
        if(left + sfcnt[lo] >= m){
            ans = max(ans, pfs[lo] - pfs[l]);
        }
    }


    cout << ans << '\n';
    
    /*
    for(ll e : pfcnt) cout << e << ' '; 
    cout << '\n';
    for(ll e : sfcnt) cout << e << ' '; 
    cout << '\n';






    */

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
