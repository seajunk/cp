#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // iterate through each element, calculate maximum size of unions if we remove the element?


    unordered_map<ll, set<ll>> m; 

    ll n; cin >> n;

    vector<set<ll>> S(n);

    for(int i = 0; i < n; i++){
        ll k; cin >> k;
        for(int j = 0; j < k; j++){
            ll in; cin >> in;
            S[i].insert(in);

            if(m.find(in) == m.end()) m[in] = {i};
            else m[in].insert(i);
        }
    }

    ll ans = 0;
    for(auto [k, v] : m){
        set<ll> curr;

        for(int i = 0; i < n; i++){
            if(v.find(i) != v.end()) continue;
            for(ll e : S[i]){
                curr.insert(e);
            }
        }
        ans = max(ans, (ll)curr.size());
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
