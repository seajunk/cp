#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> seen(n + 1, false);

    for(int i = 0; i < n; i++){
        if(!(0 <= a[i] && a[i] <= n)) continue;
        seen[a[i]] = true;
    }

    ll mx;
    for(int i = 0; i <= n; i++){
        if(!seen[i]){
            mx = i;
            break;
        }
    }

    if(mx == n){
        cout << "NO\n";
        return;
    }

    if(seen[mx + 1] == false){
        cout << "YES\n";
        return;
    } 

    ll L = LLONG_MAX, R = LLONG_MIN;

    for(ll i = 0; i < n; i++){
        if(a[i] == mx + 1){
            L = min(L, i);
            R = max(R, i);
        }
    }

    for(int i = L; i <= R; i++) a[i] = mx;

    seen.assign(n, false);

    for(int i = 0; i < n; i++){
        if(!(0 <= a[i] && a[i] <= n)) continue;
        seen[a[i]] = true;
    }
    ll newmx;
    for(int i = 0; i <= n; i++){
        if(!seen[i]){
            newmx = i;
            break;
        }
    }

    if(mx + 1 == newmx){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
