#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll mod(ll n, ll m){ return (n % m + m) % m; }

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    ll mx = LLONG_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        a[i] = a[i] % (2 * k);
    } 

    // difference array
    ll diff[2 * k];
    for(int i = 0; i < 2 *k; i++) diff[i] = 0;
    for(int i = 0; i < n; i++){
        diff[a[i]]++;
        diff[mod(a[i] + k, 2 * k)]--;
    }


    // initial = # of lights on at time mx
    ll initial = 0;
    for(int i = 0; i < n; i++){
        if(mod(mx - a[i], 2*k) < k) initial++; 
    }

    if(initial == n) cout << mx << '\n';
    else{
        ll curr = initial;
        for(int i = 1; i < 2 * k; i++){
            curr += diff[mod(mx + i, 2 * k)];
            if(curr == n){
                cout << mx + i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }










}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
