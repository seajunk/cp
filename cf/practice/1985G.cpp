#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, r, k; cin >> l >> r >> k;



    /*
       D(n) = sum of digits of n

       how many numbers in [1el, 1er) st D(kn) = kD(n)


       note [1el, 1er) is smallest number with l + 1 digits to largest number with r digits

       ie 100....000 to 999...999


       when is D(kn) = kD(n) ??


       333 * 3 = 999
       333 * 4 = 1332





       4 -> (1 1 1 1) (2 2) (3 1) (2 2)


       if k is power of 10 -> kD(n) = D(kn)
       if k * digit < 10 for all digits in n, kD(n) = D(kn)

       digit sum is additive over Z/9Z ?















































    */



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
