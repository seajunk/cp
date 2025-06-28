#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> cnt;
    for(int i = 0; i < n; i++){
        if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
        else cnt[a[i]] += 1; 
    }


    ll ans = 0; 
    ll curr = n;
    for(auto it = cnt.rbegin(); it != cnt.rend(); it++){

        // n!/k!(n-k)! = (n)(n-1)(n-2)/6
        if(it->second >= 3) ans += (it->second)*(it->second - 1)*(it->second - 2)/6; 
        if(it->second >= 2) ans += (it->second)*(it->second - 1)/2*(curr - it->second);
        curr -= it->second;
    }

    cout << ans << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
