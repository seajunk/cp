#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    unordered_map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        if(cnt.find(c[i]) == cnt.end()) cnt[c[i]] = 1;
        else cnt[c[i]] += 1; 
    }

    ll ans = 0; 
    ll onecnt = 0;
    for(auto p : cnt){
        if(p.second == 1) onecnt += 1;
        else ans += 1;
    }
    
    ans += 2 * ((onecnt + 1) / 2);

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
