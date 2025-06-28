#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll MOD = 998244353;

// a^b
ll powk(ll a, ll b){
    if(b == 0) return 1;
    ll temp = powk(a, b/2) % MOD;
    if(b % 2 == 0) return (temp * temp) % MOD;
    else return (temp * temp * a) % MOD;
}


void solve(){
    ll n; cin >> n;
    map<ll, ll> a;
    for(ll i = 0; i < n; i++){
        ll in; cin >> in;
        a[i + 1] = in;
    }

    /*
       all elements in a are initally white.
       choose >= 1 elements to paint black.
       paint all white elements which are a multiple of some black element green

       score is max of all black and green painted elements.


       get sum of scores over all possible black paintings.

       note there are 2^n - 1 ways to paint array since |P(n)| = 2^n but we dont include the empty set since at least one element must be painted.
    */




    vector<ll> lb(n + 1, -1);




    // O(nlogn)
    for(ll i = 1; i <= n; i++){
        // want all k such that k * i <= n => k <= n / i
        for(ll k = 1; k <= n/i; k++){
            lb[i] = max(lb[i], a[i * k]);
        }
    }
    // lb[i] = m <=> any subset which includes i will have score >= lb[i]

    sort(lb.begin(), lb.end(), [](auto l, auto r){return l > r;});
    //for(int i = 0; i <= n; i++) cout << lb[i] << ' '; 
    //cout << '\n';


    ll ans = 0;


    for(int i = 0; i < n; i++){
        // 2^(n - (i + 1)) guys will have score lb[i]
        ll temp = powk(2, (n - (i + 1))) % MOD;
        ans += (lb[i] % MOD) * temp;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main(){
    solve();
}
