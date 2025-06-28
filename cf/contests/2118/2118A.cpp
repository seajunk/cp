#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;


    /*
       n = 7, k = 4
       1010101

       1
       0


       11
       00

       0000011111
    */


    for(int i = 0; i < k; i++) cout << 1;
    for(int i = k; i < n; i++) cout << 0;
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
