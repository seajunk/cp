#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    /*
       binary search for x?

       fixed k
       ? k k -> if x > k (we get k*k) else (we get (k+1)*(k+1))

       find smallest k such that we get (k+1)*(k+1) 
       -> that k is x
    */

    ll lo = 2, hi = 1000;
    while(lo < hi){
        ll k = (hi - lo)/2 + lo;
        cout << "? " << k << ' ' << k << '\n';
        ll in; cin >> in;
        if(in == (k+1)*(k+1)) hi = k;
        else lo = k + 1;
    }
    if(lo == 1000){
        cout << "shit went wrong\n";
        return;
    }
    cout << "! " << lo << '\n';
}

int main(){
    ll t; cin >> t; 
    while(t--) solve();
}
