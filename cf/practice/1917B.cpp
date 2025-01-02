#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    set<char> seen;
    ll pf_unique_cnt[n];

    for(int i = 0; i < n; i++){
        if(seen.find(s[i]) == seen.end()) seen.insert(s[i]);

        pf_unique_cnt[i] = seen.size();
    }

    ll ans = 1;

    for(int i = 1; i < n; i++){
        ans += pf_unique_cnt[i];
    }

    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
