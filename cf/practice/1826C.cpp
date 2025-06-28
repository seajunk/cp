#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    // get prime factors of n, 
    // if there is a prime factor <= m, works. otherwise doesnt work

    vector<ll> factors;

    ll temp = n;
    for(int i = 2; i*i <= n; i++){
        while(temp % i == 0){
            temp /= i;
            factors.push_back(i);
        }
    }
    if(temp != 1) factors.push_back(temp);

    for(ll factor : factors){
        if(factor <= m){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
