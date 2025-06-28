#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // dont even need this actually
    ll pfcnt[n + 1];
    pfcnt[0] = 0;
    for(int i = 1; i <= n; i++) pfcnt[i] = pfcnt[i - 1] + a[i - 1];

    // want smallest i st sum[0, i) > cnt[0, i) 
    ll lo = 1, hi = n + 1; // [1, n] 

    while(lo < hi){
        ll i = (hi - lo) / 2 + lo;

        cout << "? " << i << ' ';
        for(int j = 1; j <= i; j++) cout << j << ' ';
        cout << '\n';

        ll sum; cin >> sum;

        if(sum > pfcnt[i]) hi = i;
        else lo = i + 1;
    }
    if(lo == n + 1){
        cout << "shit went wrong\n";
        return;
    }

    cout << "! " << lo << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
