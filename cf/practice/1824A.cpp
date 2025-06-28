#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    ll type1 = 0, type2 = 0;
    set<ll> type3;

    type3.insert(-1);
    for(int i = 0; i < n; i++){
        if(x[i] == -1) type1++;
        else if(x[i] == -2) type2++;
        else type3.insert(x[i] - 1);
    }
    type3.insert(m);


    vector<ll> blocks;

    for(auto it = next(type3.begin()); it != type3.end(); it++){
        blocks.push_back(*it - *prev(it) - 1);
    }

    ll ans = type3.size() - 2;

    vector<ll> pfs(blocks.size() + 1);

    pfs[0] = 0;
    for(int i = 1; i <= blocks.size(); i++) pfs[i] = pfs[i - 1] + blocks[i - 1];

    //  a b c d
    // 0 1 2 3 4
    ll gaps = 0;
    for(int i = 0; i <= blocks.size(); i++){
        ll temp = min(type1, pfs[i]) + min(type2, pfs[blocks.size()] - pfs[i]);
        gaps = max(gaps, temp);
    }
    ans += gaps;
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


