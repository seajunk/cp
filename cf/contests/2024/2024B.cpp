#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll mn = LLONG_MAX;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn ,a[i]);
    }

    sort(a.begin(), a.end());

    // 1 2 2 3 4 5 -> can get 6 cans in 6 presses
    // 0 1 1 2 3 4 -> can get 5 cans in 6 presses
    // -> can get x cans in (# of zeros) + x presses

    ll height = 0;
    ll potential_zero = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == height){
            potential_zero++;
            continue;
        }

        if((a[i] - height) * (n - i) < k){
            ans += (a[i] - height) * (n - i) + potential_zero;
            k -= (a[i] - height) * (n - i);
            potential_zero = 1;
            height = a[i];
        }
        else{
            ans += potential_zero + k;
            break;
        }
    }
    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
