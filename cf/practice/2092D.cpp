#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    /*
       can choose i in [0, n - 2] st s[i] != s[i + 1] and place character c between s[i] and s[i + 1] such that s[i] != c and c != s[i + 1]

       ie 
       LT -> LIT
       can we make string balanced after at most 2*n operations ?

       we cant remove elements, so to make string balanced, we will need at least 3*(mx occurence) - n more characters

       so we can conclude that,
       3*(mx occur) - n > 2*n -> impossible
       3*(mx occur) > 3*n 
       (mx occur) > n -> impossible

       ok but this never happens.


       if only one type of character appears in s, we are cooked since we cant make new characters

       otherwise..., always works?


       let mx = max occuence of any single character


       then we need create at least,
       need1 = mx - cnt1 1s,
       need2 = mx - cnt2 2s,
       need3 = mx - cnt3 3s,
       to make s balanced.
















































    */








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
