#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    ll n = s.size();

    // 011010010110
    ll MOD = 998244353;

    ll curr = 1;

    ll mnmoves = 0;
    ll mvcnt = 1;


    for(int i = 1; i <= n; i++){
        if(i != n && s[i] == s[i - 1]) curr++;
        else{

            mnmoves += curr-1;

            mvcnt *= curr;
            mvcnt %= MOD;

            curr = 1;
        }
    }

    for(int i = 1; i <= mnmoves; i++){
        mvcnt *= i;
        mvcnt %= MOD;
    }





    cout << mnmoves << ' ' << mvcnt << '\n';
}


// 00 11 00 

// g1 * g2 * ... gm ways to choose which guy lives
// 


// 111 -> 3 ways to 1 to live, 11 -> 2 ways to kill remaining

// 0011 -> 4 ways to choose who lives -> 2 ways to kill remaining










int main(){
    ll t; cin >> t;
    while(t--) solve();
}
