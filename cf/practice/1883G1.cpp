#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n];
    a[0] = 1;
    for(int i = 1; i < n; i++) cin >> a[i];
    ll b[n];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);


    ll lo = 0, hi = n;

    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        // can we fix in mid operations?

        bool valid = true;


        for(int i = 0; i < n - mid; i++){

            if(a[i] >= b[i + mid]){
                valid = false;
                break;
            }
        }


        if(valid) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';













}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
