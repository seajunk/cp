#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // if any guy a[i] is less than or equal to distance from i to farthest index from i times two then doesnt work, otherwise works?

    for(ll i = 0; i < n; i++){
        if(a[i] <= 2 * max(abs(n - 1 - i), i)){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
