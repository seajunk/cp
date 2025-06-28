#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       if odd and even exist in a then try k = 2

       try k = 4
       if every guy is even then only possible values after mod k are 1 or 3
       if every guy is odd then only possible values after mod k are 0 or 2

       try k = 8
       wlog a[i] % 2 = 1 and a[i] % 4 = 3
       then only possible values after mod k are (cant be 0 + 2n and must be 3 + 4n)(0 2 4 6 8 1 5)
       so must be either 3 or 7
       ... continue on like this

    */
    ll n; cin >> n;
    ll a[n];
    ll k = 2;

    for(int i = 0; i < n; i++) cin >> a[i];


    while(true){
        set<ll> curr;
        for(int i = 0; i < n; i++) curr.insert(a[i] % k);
        if(curr.size() == 2){
            cout << k << '\n';
            return;
        }
        k *= 2;
    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
