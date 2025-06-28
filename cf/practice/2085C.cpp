#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y; cin >> x >> y;

    /*
       want k such that

       (x + k) + (y + k) = (x + k) ^ (y + k)

       note 
       a + b == a ^ b iff a & b == 0

       make the bigger of (x + k) and (y + k) into 10000....000
       
       numbers of the form 2^k dont share any bits with numbers less than it




    */

    if(x == y){
        cout << -1 << '\n';
        return;
    }
    cout << (1ll << 32) - max(x, y) << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
