#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll a, b, c; cin >> a >> b >> c;

    // (1) can make b == c => a can be last
    // (2) a can be last => can make b == c(?)

    // when can you make b == c ?
    // wlog supose b > c
    // either b goes down and/or c goes up
    // b can go down from making more c or a, making a also lowers c so distance between b c doesnt change
    // c can go up from making more c
    // is making c always optimal ?
    // 1 6 4 >> 0 5 5
    // when does making a work ? 

    // 91 41 11
    // need to up a, lower b
    // 5 3 0
    // 4 2 1
    // 3 3 0
    // 3 1 0
    // 2 0 1
    // 1 1 0


    vector<ll> ans(3, 0);
    if(a*b != 0 && a % 2 == b % 2) ans[2] = 1;
    if(a*c != 0 && a % 2 == c % 2) ans[1] = 1;
    if(c*b != 0 && c % 2 == b % 2) ans[0] = 1;





    for(ll e : ans) cout << e << ' ';
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
