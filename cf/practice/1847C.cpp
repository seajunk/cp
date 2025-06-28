#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 1 1 0 1
    // 1 0 1 0
    // 0 1 1 1


    // 1 2 3 4 5 6 7 8 (3 4 5 6 7 8) 

    // can actually get any contiguous subarray xor

    // so question reduces to finding max xor on subarrays


    // since a[i] <= 2^8, we can iterate over each value?

    // for some fixed 0 <= x <= 2^8, how to check if x is xor of some subarray in a
    // instead of some fixed x, we essentially iterate through every possible prefix xor since thats actually smaller in this casea since a[i] <= 2^8

    // note pfxor works 

    vector<bool> possible(257, false); // possible[i] = i seen as a prefix so far?

    ll curr = 0;
    ll ans = 0;
    possible[0] = true;

    for(int i = 0; i < n; i++){
        
        curr ^= a[i]; // xor [0, i]
        possible[curr] = true; // possible has seen prefixes on [0, i] 
        ans = max(ans, curr);

        for(int j = 0; j <= 256; j++){
            if(possible[j]){
                ans = max(ans, j^curr);
            }
        }
    }

    cout << ans << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

