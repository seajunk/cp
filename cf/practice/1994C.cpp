#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x; cin >> n >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    /*
       choose [l, r]
       eat a[i] for i = l to r
       if sum >= x, sum is reset to 0

       want number of pairs (l, r) such that after opeations, final sum is != 0


       how to check if (l, r) results in final value of 0


       sum[l, r] < x -> final value != 0

       final value == 0 -> sum becomes >= x in the last operation



       dp[l, r] = final value of a[l, r]
       dp[l, r] can be determined from dp[l, r - 1] and a[r]


       for a fixed r, # of l st (l, r) != 0 is ...
       count of dp[l, r - 1] st dp[l, r - 1] + a[r] < x





       idea,
       fix l, nxt[l] = smallest index r such that sum [l, r) >= x
       get nxt[l] for each l = 0, ... , n-1.

       note that we get a sort of dag from this
       and # of pairs (l, r) whose final value is non zero is the # of nodes on the path from l to the farthest reachable node - 1


       then,
       first run, left to right, compute nxt[l], O(nlogn)
       second run, right to left, compute the current # of nodes from node i to the end O(n)
    */


    ll pfs[n + 1];
    pfs[0] = 0;
    for(int i = 1; i <= n; i++) pfs[i] = pfs[i - 1] + a[i - 1];
    vector<ll> nxt(n, INT_MAX);

    for(int l = 0; l < n; l++){
        // find smallest r such that pfs[l, r) >= x
        ll lo = l + 1, hi = n + 1;
        while(lo < hi){
            ll r = (hi - lo)/2 + lo;
            if(pfs[r] - pfs[l] > x) hi = r;
            else lo = r + 1;
        }
        if(lo != n + 1) nxt[l] = lo;
    }


    ll length[n + 1]; // length[i] = # of nodes in the longest path starting from node i
    length[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(nxt[i] == INT_MAX) length[i] = 1;
        else length[i] = length[nxt[i]] + 1;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += n - i - (length[i] - 1);
    }
    cout << ans << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
