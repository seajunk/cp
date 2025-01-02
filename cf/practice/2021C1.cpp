#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n, m, q; cin >> n >> m >> q;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll b[m];
    for(int i = 0; i < m; i++) cin >> b[i];

    set<ll> seen;
    vector<ll> order;

    for(int i = 0; i < m; i++){
        if(seen.find(b[i]) == seen.end()){
            order.push_back(b[i]);
            seen.insert(b[i]);
        }
    }

    ll ptr = 0;
    while(ptr < order.size()){
        if(order[ptr] != a[ptr]){
            cout << "TIDAK\n";
            return;
        }
        ptr++;
    }
    cout << "YA\n";


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
