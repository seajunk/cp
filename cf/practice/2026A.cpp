#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y, k; cin >> x >> y >> k; 

    cout << 0 << ' ' << 0 << ' ' << min(x, y) << ' ' << min(x, y) << '\n';
    cout << 0 << ' ' << min(x, y) << ' ' << min(x, y) << ' ' << 0 << '\n';

    
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
