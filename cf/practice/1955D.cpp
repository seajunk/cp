#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    unordered_map<ll, ll> cntb, cnta;
    for(int i = 0; i < m; i++) cntb[b[i]] = 0;
    for(int i = 0; i < m; i++) cntb[b[i]]++;
    for(int i = 0; i < n; i++) cnta[a[i]] = 0;
    for(int i = 0; i < m; i++) cnta[a[i]]++;

    // conj: subsegment of a works if |subsegment intersection b| >= k
    ll curr = 0;
    ll ans = 0;
    for(pair<ll, ll> p : cnta){
        if(cntb.find(p.first) != cntb.end()) curr += min(cntb[p.first], p.second);
    }
    if(curr >= k) ans++;

    for(int i = m; i < n; i++){
        if(cntb.find(a[i-m]) != cntb.end()){
            if(cnta[a[i-m]] <= cntb[a[i-m]]) curr--;
        }
        cnta[a[i-m]]--;


        if(cntb.find(a[i]) != cntb.end()){
            if(cnta[a[i]] < cntb[a[i]]) curr++;
        }
        cnta[a[i]]++;

        if(curr >= k) ans++;
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

