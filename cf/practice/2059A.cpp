#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    set<ll> cnta, cntb;

    for(int i = 0; i < n; i++){
        cnta.insert(a[i]);
        cntb.insert(b[i]);
    }

    if(cnta.size() * cntb.size() >= 3) cout << "Yes\n";
    else cout << "No\n";



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
