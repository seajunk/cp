#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

void solve(){
    ll n; cin >> n;

    map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        if(cnt.find(in) == cnt.end()) cnt[in] = 1;
        else cnt[in]++;
    }

    ll ans = 0;

    for(auto p : cnt){
        ll k = p.first;


        // maximal runs
        while(cnt[k] > 0){
            ans += 1;
            ll curr = k;
            while(cnt.find(curr) != cnt.end() && cnt[curr] > 0){
                cnt[curr]--;
                curr++;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
