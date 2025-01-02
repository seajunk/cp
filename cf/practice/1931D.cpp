#include <iostream>
#include <map>
#include <vector>
#define ll long long
using namespace std;

// (ai + aj) % x == 0
// (ai % x + aj % x) % x == 0;

// (ai - aj) % y == 0
// (ai % y - aj % y) % y == 0


void solve(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i] % x;
        c[i] = a[i] % y;
    }

    /*
    for(int i = 0; i < n; i++){
        vector<ll> next = {(x - b[i]) % x, c[i]};
        if(h.find(next) == h.end()) h[next] = 0;

        vector<ll> curr = {b[i], c[i]};
        if(h.find(curr) != h.end()) h[curr]++;
    }
    */

    map<vector<ll>, ll> cnt;
    ll ans = 0;

    for(int i = 0; i < n; i++){
        vector<ll> pair = {(x - b[i]) % x, c[i]};
        if(cnt.find(pair) != cnt.end()){
            ans += cnt[pair];
        }

        vector<ll> curr = {b[i], c[i]};
        if(cnt.find(curr) == cnt.end()) cnt[curr] = 1;
        else cnt[curr]++;
    }

    cout << ans << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
