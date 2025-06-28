#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll MOD = 1000000000 + 7;

    /*


       get cnt0, cnt1. 
       let l = max(k/2 + 1, k - cnt0), r = min(cnt1, k)

       then 
       ans = 
         choose(k, l)*choose(k, k - l) 
       + choose(k, l+1)*choose(k, k - (l + 1)) 
       + ... 
       + choose(k, r)*choose(k, k - r)

       precompute factorials
       -> O(n) ? 

    */


    vector<ll> factorial(n + 1, 0);
    factorial[0] = 1;
    for(int i = 1; i <= n; i++){
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= MOD;
    }

    function<ll(ll, ll)> C = [&](ll n, ll k){
        ll denom = (factorial[k] % MOD) * (factorial[n - k] % MOD);
        denom %= MOD;
        return (factorial[n]) / denom;
    };

    ll cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cnt0++;
        else cnt1++;
    }

    ll ans = 0;
    /*
       min of 1's, max of 1's

       need atleast (k/2 + 1) 1's
       need atleast k - cnt0 1's

       need at most k 1's
       need at most cnt1 1's
    */


    for(int i = max(k/2 + 1, k - cnt0); i <= min(k, cnt1); i++){
        // ans += choose(cnt1, i) * choose(cnt0, i - k)
        //cout << i << ' ';
        //ll first = (factorial[cnt1]) / ((factorial[i] * factorial[cnt1 - i]) % MOD);
        //ll second = (factorial[cnt0]) / ((factorial[k - i] * factorial[cnt0 - (k - i)]) % MOD) ;
        ll first = C(cnt1, i);
        ll second = C(cnt0, k - i);

        ll temp = first * second % MOD;

        ans += first * second;
        //cout << first * second << " added to ans\n";
        ans %= MOD;
    }

    cout << ans << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
