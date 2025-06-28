#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    /*
       have 2^n kg of wood.

       need k kg of wood 


       let d be the distance between msb of k and n.

       eg for 2^4 = 10000, 3 = 00101, d = 1

       then from msb to lsb of 3, if bsk[i] == 1, ans *= 2
    */

    bitset<64> kbs(k);


    ll ans = 1;
    ll curr = 1;

    for(int i = n - 1; i >= 0; i--){
        if(kbs[i] == 1) ans = max(ans, curr);
        curr += 1;
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
