#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<ll, vector<ll>>> a(n, {0, vector<ll>(m + 1)});

    for(int i = 0; i < n; i++){
        a[i].first = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i].second[j];
            a[i].first += a[i].second[j];
        }
    }


    sort(a.begin(), a.end(), [](auto l, auto r){
            return l.first > r.first;
            });

    vector<ll> concat;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            concat.push_back(a[i].second[j]);
        }
    }

    ll ans = 0;

    for(int i = 0; i < n * m; i++){
        ans += concat[i] * (n * m - i);
    }


    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
