#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;

    set<pair<ll, ll>> queen, king;

    queen.insert({xq + a, yq + b});
    queen.insert({xq + a, yq - b});
    queen.insert({xq - a, yq + b});
    queen.insert({xq - a, yq - b});
    queen.insert({xq + b, yq + a});
    queen.insert({xq + b, yq - a});
    queen.insert({xq - b, yq + a});
    queen.insert({xq - b, yq - a});
    queen.insert({xq + a, yq + b});

    king.insert({xk + a, yk + b});
    king.insert({xk + a, yk - b});
    king.insert({xk - a, yk + b});
    king.insert({xk - a, yk - b});
    king.insert({xk + b, yk + a});
    king.insert({xk + b, yk - a});
    king.insert({xk - b, yk + a});
    king.insert({xk - b, yk - a});

    ll ans = 0;
    for(pair<ll, ll> p : king) if(queen.find(p) != queen.end()) ans++;  
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

