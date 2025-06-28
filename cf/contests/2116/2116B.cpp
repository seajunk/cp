#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2[100001];
ll MOD = 998244353;

void solve(){
    ll n; cin >> n;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    ll q[n];
    for(int i = 0; i < n; i++) cin >> q[i]; 


    /*
       r[i] = max(2^p[j] + 2^q[i - j]) for j <= i




    */


}

int main(){
    ll curr = 2;
    for(int i = 1; i <= 100000; i++){
        pow2[i] = curr;
        curr *= 2;
        curr %= MOD;
    }


    ll t; cin >> t;
    while(t--) solve();


}
