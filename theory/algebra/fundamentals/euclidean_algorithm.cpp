#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
   Euclids algorithm computes gcd(a, b)

   note gcd(a, b) is the largest k which divides both a and b
   by definition gcd(0, 0) = 0

   note that the set of divisors of (a, b) is the same as (a, a - b) where a > b 

   then if we iteratively subtract from a, b, then we eventually will end up with the pair(gcd(a, b) ,0)

*/

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << gcd(a, b) << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


