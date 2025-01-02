#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll score = 0;
    for(int i = 0; i < n - 2; i++){
        score += a[i];
    }
    ll ans = a[n - 1] - (a[n - 2] - score);

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
