#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void solve(){
    ll n; cin >> n;
    ll MOD = 1000000007;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // >> 3 2 3 
    // >> 7
    
    // ((3 * 2) + (2 * 3) (3 * 3)) / 3 = 21 / 3
    // a1 a2 a3 a4 a5
    // (1, 2) (1, 3) (1, 4) (1, 5) (2, 3), (2, 4) (2, 5) (3, 4) (3, 5) (4, 5)

    // (1 * 2) + (1 * 3) + (1 * 4) + (1 * 5) + (2 * 3) + * (2 * 4) + (2 * 5) + (3 * 4) + (3 * 5) + (4 * 5)
    // (1)(2 + 3 + 4 + 5) + (2)(3 * 4 * 5) + ...
    ll ps[n + 1];
    ps[0] = 0;
    for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i - 1];

    ll P = 0;
    for(int i = 0; i < n; i++){
        P += (a[i] * (ps[n] - ps[i + 1])) % MOD; 
    }

    ll Q = n * (n - 1) / 2;

    ll Qinv = gcd(MOD, Q);
    // euclids algorithm to get Q^{-1} ?? 


    
    cout << Q * Qinv << '\n';




    // 2 2 2 4
    // (2 * 2) + (2 * 2) + (2 * 4) + 
    // (2 * 2) + (2 * 4) + 
    // (2 * 4) + 
    // 0
    // 4 + 4 + 8 + 4 + 8 + 8 = 8 + 8 + 8 + 8 + 4 = 






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
