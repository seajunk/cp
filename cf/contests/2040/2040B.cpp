#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    // need to make 


    // 20
    // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1

    // 0 + 2 -> 4
    // 4 + 1 -> 10
    // 10 + 1 -> 22

    ll ans = 1;

    ll curr = 1;

    while(curr < n){
        ans++;
        curr += 1;
        curr *= 2;
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
