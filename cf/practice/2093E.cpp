#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    /*
       want to partition a into k subarrays such that the min of the mex of the subarrays is maximized


       binary search for x, then greedy ?
    */


    // x /in [0, n], maximize
    ll lo = -1, hi = n;
    while(lo < hi){
        ll x = (hi - lo + 1)/2 + lo;


        vector<bool> seen(x, false);
        ll currcnt = 0;
        ll cnt = 0;

        for(int i = 0; i < n; i++){
            if(0 <= a[i] && a[i] < x){
                if(!seen[a[i]]) currcnt++;
                seen[a[i]] = true;
            }
            if(currcnt == x){
                cnt++;
                currcnt = 0;
                seen.assign(x, false);
            }
        }

        if(cnt >= k) lo = x;
        else hi = x - 1;
    }
    if(lo == -1){
        cout << "shit went wrong\n";
        return;
    }

    cout << lo << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
