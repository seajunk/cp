#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    unordered_map<ll, ll> cnt;
    
    ll mx = 0;
    for(int i = 0; i < n; i++){
        if(cnt.find(h[i]) == cnt.end()) cnt[h[i]] = 1;
        else cnt[h[i]]++;
        mx = max(mx, cnt[h[i]]);
    }


    cout << n - mx << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

