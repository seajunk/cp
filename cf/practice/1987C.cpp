#include <iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, h[N], dp[N], ans;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];

    // 4 3 2 1 0 -> 3 2 1 0 0 -> 2 1 0 0 0
    // 1 2 3 4 5 -> 1 2 3 4 4 -> 1 2 3 4 3 -> 1 2 3 3 3
    //               1 1 1 0      1 1 1-1
    // 1 3 -> 1 2 -> 1 1 -> 1 0 -> 0 0
    // 3 1 2 -> 
    // dp[n] == h_n
    // if h_i <= h_i+1 =>   dp[i] = d[i + 1] + 1
    // else                 dp[i] = h_i 

    ans = h[n];
    dp[n] = h[n];
    for(ll i = n - 1; i >= 1; i--){
        dp[i] = max(h[i], dp[i + 1] + 1);

        ans = max(ans, dp[i]);
    }

    cout << dp[1] << '\n';





}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
