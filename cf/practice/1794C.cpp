#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int k = 1; k <= n; k++){
        // want smallest i in [0, k) such that a[k - 1 - i] >= i + 1

        ll lo = 0, hi = k;
        while(lo < hi){
            ll i = (hi - lo)/2 + lo;
            if(a[i] >= k - i) hi = i;
            else lo = i + 1;
        }
        if(lo == k){
            cout << "shit went wrong\n";
            return;
        }
        cout << k - lo << '\n';
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
