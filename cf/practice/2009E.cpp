#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;



    // case pf[i] >= sf[i];
    ll mn = LLONG_MAX;

        ll lo = 0, hi = n - 1;
    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;

        // want smallest i st pf[i] >= sf[i]
        // F F F , ... F T T T

        ll pf = ((k + mid) * (k + mid + 1))/2 - (k*(k-1))/2; // sum on [k, k + mid] 
        ll sf = (k + n - 1)*(k + n)/2 - (k + mid + 1)*(k + mid)/2; // sum on [k + mid + 1, k + n - 1] 

        mn = min(mn, abs(pf - sf));

        if(pf < sf) lo = mid + 1;
        else hi = mid;
    }

    cout << mn << '\n';













}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
