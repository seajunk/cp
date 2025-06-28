#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
   Binary exponentiation is a method to compute a^n in O(logn) time.

   The key idea is to split a^n into products of the form a^(2^i) where the term 2^i corresponds to the binary representation of n.

   e.g.
   3^9 = 3^(8 + 1) = 3^8 * 3^1
   3^15 = 3^(8 4 2 1) = 3^8 * 3^4 * 3^2 * 3^1

   So you only need to compute O(logn) number of exponents to calculate a^n

   this is formulated as the following recusion
   a^n = 
   1 ,if n == 0, 
   a^(n/2)^2 ,if n even
   (a^((n - 1)/2)^2)*a ,if n odd
*/

ll binexp(ll a, ll n){
    /*
       each recursive call we add on to the answer the 0th bit.
    */
    if(n == 0) return 1;
    ll sub = binexp(a, n/2);
    if(n % 2 == 0) return sub*sub; 
    else return sub*sub*a;
}

void solve(){
    ll a, n; cin >> a >> n;
    cout << binexp(a, n) << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


