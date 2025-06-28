#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       odd from top, can remove and add to score
       even from top, can remove

       note performing operation on a[i] doesnt change the parity for any j < i 


       -4 1 -3 5 -> 5

       1 -2 3 -4 -> 4

       -1 3 -5 -> 2

       -1 -> 0



       greedy / dp ? 


       if were gonna go right to left, were gonna need some kind of precomputation first


       if odd and postiive, take
       if odd and negative, skip it
       if even and negative, skip it

       if even and positive

       we want see if we can take some a guy above current guy to make current guy odd, or if its unreasonable to try to take this guy

       find largest i < current index such that

       0 -1 -100 10
    */


    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + max(0ll, a[i - 1]);


    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll curr = a[i] * (i%2 == 0) + pfs[n] - pfs[i + 1];
        ans = max(ans, curr);
    }

    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

/*
   idea is that if we decide before hand to take some a[i], we can get all positive cards below a[i]. we can do this by taking all positive cards on odd index, then take a[i] to shift parity and take all the positive guys we missed
*/
