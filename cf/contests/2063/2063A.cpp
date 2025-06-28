#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, r; cin >> l >> r;

    // c: a minimal coprime segment have len < 4 since any 4 length sumsegment has two even numbers.

    // c: if n is odd, n, n + 2 are co prime? 

    // for any even number n, [n, n + 1] only co prime segment
    // for any odd n > 1, [n, n + 1], [n, n + 1, n + 2](?) are only co prime
    
    if(l == 1 && r == 1) cout << 1 << '\n';
    else cout << r - l << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
