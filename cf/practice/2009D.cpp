#include <iostream>
#include <unordered_set>
#define ll long long
using namespace std;

void solve(){
    unordered_set<ll>  low, high;

    ll n; cin >> n;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        if(y == 0) low.insert(x); 
        else high.insert(x);
    }

    ll ans = 0;
    for(ll x : low){
        if(high.find(x - 1) != high.end() && high.find(x + 1) != high.end()) ans ++;
        if(high.find(x) != high.end()) ans += high.size() - 1;
    }
    for(ll x : high){
        if(low.find(x - 1) != low.end() && low.find(x + 1) != low.end()) ans ++;
        if(low.find(x) != low.end()) ans += low.size() - 1;
    }

    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
