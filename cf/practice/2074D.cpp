#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    ll x[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    ll r[n];
    for(int i = 0; i < n; i++) cin >> r[i];

    // sum(r) = m
    // so we can iterate over all points on the circle without tle


    map<ll, ll> points; // (x coordinate, number of points on the x coordinate)

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= r[i] ; j++){
            if(points.find(x[i] + j) == points.end()) points[x[i] + j] = (2*(ll)sqrt(r[i]*r[i] - j*j) + 1);
            else points[x[i] + j] = max(points[x[i] + j], (2*(ll)sqrt(r[i]*r[i] - j*j) + 1)); 

            if(points.find(x[i] - j) == points.end()) points[x[i] - j] = (2*(ll)sqrt(r[i]*r[i] - j*j) + 1);
            else points[x[i] - j] = max(points[x[i] - j], (2*(ll)sqrt(r[i]*r[i] - j*j) + 1)); 
        }
    }

    ll ans = 0;
    for(auto p : points){ ans += p.second; } 

    cout << ans << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
