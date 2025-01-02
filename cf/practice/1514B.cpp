#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    // count # of arrays of len n with elem <= 2^k - 1 with AND = 0 with maximal sum

    // 2 2 -> [3 0] [0 3] [1 2] [2 1]
    // NOT [0 1] since sum not maximal


    // 11 00 | 10 01 




    // conj: all elements must be disjoint ie no shared 1's
    // conj: unnion elements has no 0's

    // each bit 0 through k-1 can go to any one of the n elements n^(k) ?


    ll ans = 1;

    for(int i = 0; i < k; i++){
        ans *= n;
        ans %= 1000000007;
    }

    cout << ans << '\n';
















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
