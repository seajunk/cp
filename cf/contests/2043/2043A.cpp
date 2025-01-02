#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    ll ans = 1;
    while(n > 3){
        ans *= 2;
        n /= 4;
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
