#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       need to construct permutation p[n] such that


       a[i] = the # of iterations it took to remove p[i]


       odd operations remove all non local minimum elements
       even operations remove all non local maximum elements
    */

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

