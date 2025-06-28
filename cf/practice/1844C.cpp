#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    if(n == 1){
        cout << c[0] << '\n';
        return;
    } 

    // 1 2 3 4 5 6 7 8 9 10
    // (2 4) (5 7) 8

    // 1 (2 4) 5 6 7 8 9 10
    // 1 (2 4) 5 6 (7 9) 10

    vector<ll> even;
    vector<ll> odd;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) even.push_back(c[i]);
        else odd.push_back(c[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    ll ans = LLONG_MIN;

    ll sum = *even.rbegin();
    for(auto it = next(even.rbegin()); it != even.rend(); it++){
        if(*it < 0) break;
        sum += *it;
    }

    ans = max(ans, sum);

    sum = *odd.rbegin();
    for(auto it = next(odd.rbegin()); it != odd.rend(); it++){
        if(*it < 0) break;
        sum += *it;
    }

    ans = max(ans, sum);

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
