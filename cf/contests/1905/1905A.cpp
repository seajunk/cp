#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // 1 2 3 x 5 6 7
    // 1 x 3 4 5 6 7
    // x 2 3 4 5 x 7
    // 1 2 x 4 5 6 7
    // 1 2 3 4 x 6 x
    ll n, m; cin >> n >> m;
    cout << max(n, m) << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
