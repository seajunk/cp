#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, bool> m; // this is stupid and cringe

void solve(){
    ll n; cin >> n;
    if(m.find(n) != m.end()){
        if(m[n]) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    
    // snowflake has k^0 + k^1 + k^2 + ... verticies 
    // geometric series?
    // sum of first i term = (1-k^i)/(1-k)

    // idea: iterate over k and do binary search with geometric series formula ?

    // k <= n

    // number of terms in geometric series with k <= n (by a lot)
    // need to bound number of terms in the geometric series 
    // find first smallest j st k^j > n, use j as upperbound on number of terms ? maybe overflow maybe 

    if(n < 7){ // minimum snwoflake with k = 2 has 7 vertices
        m[n] = false;
        cout << "NO\n";
        return;
    }

    for(ll k = 2; k <= n; k++){
        ll curr = 1;
        ll j = 0;

        // logk(n) 
        while(curr <= n){
            j++;
            curr *= k;
        }
        
        ll sum = 1 + k + k*k;
        if(sum > n) continue; // if n less than minimum k snowflake, k cant be valid

        curr = k*k*k;
        while(sum < n){
            sum += curr;
            curr *= k;
        }
        if(sum == n){
            m[n] = true;
            cout << "YES\n";
            return;
        }

    }
    m[n] = false;
    cout << "NO\n";
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
