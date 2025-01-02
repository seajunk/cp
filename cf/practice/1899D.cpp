#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 2^a[0], ..., 2^a[n - 1]

    // # of pairs (i, j) st a^b = b^a where a = 2^a[i], b = 2^a[j]

    // 2^1 = 2
    // 2^2 = 4
    // 2^4 = 4^2

    // 1 2 work
    // equal work
    // any equal pair works
    // does any other pair work? 

    map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
        else cnt[a[i]]++;
    }

    ll ans = 0;
    for(auto [k, v] : cnt){
        ans += v*(v - 1) / 2;
    }

    if(cnt.find(1) != cnt.end() && cnt.find(2) != cnt.end()){
        ans += cnt[1] * cnt[2];
    }

    cout << ans << '\n';











}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
