#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;

    for(int i = 0; i < n; i++){
        while(a[i] % 2 == 0){
            a[i] /= 2;
            sum++;
        }
    }

    if(sum >= n){
        cout << 0 << '\n';
        return;
    }

    vector<ll> twocnt;
    for(int i = 1; i <= n; i++){
        ll temp = i;
        ll curr = 0;
        while(temp % 2 == 0){
            curr += 1;
            temp /= 2;
        }

        twocnt.push_back(curr);
    }

    sort(twocnt.begin(), twocnt.end());


    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += 1;
        sum += twocnt[i];
        if(sum >= n){
            cout << ans << '\n';
            return;
        }
    }

    cout << -1 << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

