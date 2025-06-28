#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll msb(ll n){
    ll ans = 0;
    while(n > 1){
        ans++;
        n /= 2;
    }

    return ans;
}

ll f(ll a, ll b){
    return min(a, b);
}




void solve(){
    ll n, s; cin >> n >> s;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll pfs[n];
    pfs[0] = a[0];
    for(int i = 1; i < n; i++) pfs[i] = pfs[i - 1] + a[i];

    ll k = msb(n);
    vector<vector<ll>> st(k + 1, vector<ll>(n, -1));

    for(int i = 0; i < n; i++) st[0][i] = pfs[i];


    for(int r = 1; r <= k ; r++){
        for(int c = 0; c + (1ll << r) - 1 < n; c++){
            st[r][c] = f(st[r - 1][c], st[r - 1][c + (1ll << (r - 1))]);
        }
    }

    ll lg[n+1];

    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

    // maxmiz over [0, n]


    bool found = false;
    ll L = -1, R = -1;
    ll lo = 0, hi = n;
    while(lo < hi){
        ll mid = (hi - lo + 1)/2 + lo; // sliding window size

        bool works = false;

        ll mnpfs = LLONG_MAX;
        ll curr = 0;

        for(int i = 0; i < mid; i++){
            curr += a[i];
            mnpfs = min(curr, mnpfs);
        }

        if(s + mnpfs >= 0){
            works = true;
            found = true;
            L = 0, R = mid - 1;
        }


        for(int i = mid; i < n; i++){

            // sliding window loses a[i - mid]
            // sliding window gains a[i]
            // current window is [i - mid + 1, i]

            // [l, r], [l, r)

            ll l = i - mid + 1, r = i;
            ll j = lg[r - l + 1];
            ll mn = min(st[j][l], st[j][r - (1ll << j) + 1]) - pfs[l - 1];

            if(s + mn >= 0){
                found = true;
                works = true;
                L = l;
                R = r;
            }
        }
        if(works) lo = mid;
        else hi = mid - 1;
    }

    if(!found){
        cout << -1 << '\n';
        return;
    }

    cout << (L + 1) << ' ' << (R + 1) << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
