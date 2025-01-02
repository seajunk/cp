#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, L; cin >> n >> m >> L;
    map<ll, vector<ll>> interval;
    interval[0] = {};


    for(int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        l--;
        interval[l] = {};
        interval[r] = {};
    }

    for(int i = 0; i < m; i++){
        // put each powerup in corresponding interval?

        ll x, v; cin >> x >> v;
        x--;

        prev(interval.upper_bound(x))->second.push_back(v);
    }

    ll power = 1;
    bool reg = true;
    priority_queue<ll> powerups;
    ll ans = 0;


    for(auto it = interval.begin(); it != interval.end(); it++){
        if(reg){
            for(ll e : it->second){
                powerups.push(e);
            }
        }
        else{
            ll distance = next(it)->first + 1 - it->first;
            while(power < distance){
                if(powerups.size() == 0){
                    cout << -1 << '\n';
                    return;
                }
                power += powerups.top();
                ans++;
                powerups.pop();
            }
        }
        reg = !reg;
    }

    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


