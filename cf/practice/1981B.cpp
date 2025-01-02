#include <iostream>
#include <bitset>
#include <cstdint>
#include <assert.h>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;


// 0 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1111 10000 10001 10010 10011

ll f(ll n, ll m){
    if(m == 0){
        return n;
    }
    else{
        if(n == 0){
            return f(n, m - 1) | f(n + 1, m - 1);
        }
        else{
            return f(n - 1, m - 1)| f(n, m - 1) | f(n + 1, m - 1);
        }
    }
}


ll interval_or(ll l, ll r){
    ll ans = 0;
    for(int i = 0; i < 64; i++){
        if((l >> i) & 1 || (r >> i) & 1) ans = ans | (1 << i);
        else{
            ll lb = l & ~((1 << i) - 1);
            ll ub = lb | (1 << i);
            if(r >= ub) ans = ans | (1 << i);
        }
    }
    cout << bitset<64>(l) << '\n' << bitset<64>(r) << '\n';
    cout << ans << '\n';
    return ans;
}

ll interval_or2(ll l, ll r){
    ll j = -1;
    for(int i = 63; i >= 0; i--){
        if((r & (1ULL << i)) && !(l & (1ULL << i))){
            j = i;
            break;
        }
    }

    ll ans = j == -1 ? r : r | ((1ULL << j) - 1ULL);
    //cout << bitset<64>(r) << '\n' << bitset<64>(l) << '\n' << bitset<64>(ans) << '\n'; 
    return ans;
}

// figure out how to bitwise or in an interval [l, r]
void solve(){
    ll n, m; cin >> n >> m;
    cout << interval_or2(max(n - m, 0ll), n + m) << '\n';
    //interval_or2(n, m);
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}

