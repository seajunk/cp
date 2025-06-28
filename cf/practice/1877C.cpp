#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    /*
       count number of choices for a[n] such there are atleast k distinct values of a[i] := a[i + 1] % i 

       if choose final value as 0, then 1 distinct value
       if choose final value as <= n, then 2 distinct value 

       >> 3 10 2
       0 0 0 0
       1 1 1 0
       2 2 0 0
       3 3 0 0
       4 1 1 0
       5 2 0 0
       6 0 0 0
       7 1 1 0
       8 2 0 0

       any k > 3 is impossible ?

       k = 1, only 0 works
       k = 2, [1, n] work
       k = 3, [n + 1, m] works
    */
    ll n, m, k; cin >> n >> m >> k;

    if(k > 3){
        cout << 0 << '\n';
        return;
    }

    if(k == 1){
        cout << 1 << '\n';
        return;
    }

    if(k == 2){
        cout << min(n, m) + max(0ll, m - n) / n << '\n'; 
        return;
    }

    if(k == 3){
        cout << max(0ll, m - n) - max(0ll, m - n) / n << '\n';
        return;
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
